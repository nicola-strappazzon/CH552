#include <stdint.h>
#include "ch552.h"
#include "utils.h"

/*
 * PWM_CTRL bit masks. ch552.h declares these as SBIT, but PWM_CTRL (0x9D)
 * is not a bit-addressable SFR on MCS51, so we need real masks to OR them.
 */
#define PWM1_OUT_EN  0x04   // bit 2: enable PWM1 output
#define PWM_CLR_ALL  0x02   // bit 1: hold PWM counters/FIFO in reset
#define PWM1_POLAR   0x20   // bit 5: 0 = idle low/active high, 1 = idle high/active low

/*
 * Hardware PWM1 fade on P3.0.
 *
 * PWM1 is an 8-bit hardware PWM: write 0..255 into PWM_DATA1 and the
 * peripheral generates the waveform autonomously - no timer ISR needed.
 *
 * By default PWM1 comes out on P1.5; setting bPWM1_PIN_X in PIN_FUNC
 * remaps it to P3.0 (see datasheet, Pin Definitions).
 *
 * PWM frequency = F_sys / (256 * (PWM_CK_SE+1))
 * At F_sys = 12 MHz and PWM_CK_SE = 0: ~46.8 kHz, well above audible
 * range and visually smooth on an LED.
 *
 * Polarity:
 *   bPWM1_POLAR = 0 -> idle low, duty drives high (LED to GND through R)
 *   bPWM1_POLAR = 1 -> idle high, duty drives low (LED to VCC through R)
 * The current fade example uses LED-to-VCC wiring; we mirror that here.
 */

void main(void) {
    uint8_t d;

    init();

    // Route PWM1 to P3.0 instead of the default P1.5.
    PIN_FUNC |= bPWM1_PIN_X;

    // P3.0 as push-pull output so the PWM can drive both rails.
    P3_MOD_OC &= ~(1 << 0);
    P3_DIR_PU |=  (1 << 0);

    // Free-running clock (no extra division). 8-bit period -> ~46 kHz @ 12 MHz.
    PWM_CK_SE = 0;

    PWM_DATA1 = 0;                  // start at duty 0
    // PWM_CTRL reset value is 0x02 -> bPWM_CLR_ALL is set, peripheral is held
    // in reset. Writing the mask below clears it and enables PWM1 output.
    PWM_CTRL  = PWM1_POLAR          // idle high, active low (LED to VCC)
              | PWM1_OUT_EN;        // enable PWM1 output

    while (1) {
        for (d = 0; d < 255; d++) {
            PWM_DATA1 = d;
            delay_ms(10);
        }
        for (d = 255; d > 0; d--) {
            PWM_DATA1 = d;
            delay_ms(10);
        }
    }
}
