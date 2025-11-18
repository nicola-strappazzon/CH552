#include <stdint.h>
#include <stdbool.h>
#include "ch552.h"

#define FREQ_SYS 24000000UL

volatile __bit pwm_out;          // estado actual para P3.0 (opcional)
volatile uint8_t pwm_cnt = 0;    // contador PWM [0..63]
volatile uint8_t duty    = 0;    // duty actual [0..63]

// --- Timer1: delay de 1 ms bloqueante ---
static void delay_ms(uint16_t ms) {
    // Timer1 modo 1 (16 bits), tick = Fsys/12 = 2 MHz → 2000 ticks = 1 ms
    // Reload: 65536 - 2000 = 63536 = 0xF7D0
    TMOD = (TMOD & 0x0F) | 0x10;   // T1 Modo 1
    while (ms--) {
        TR1 = 0;
        TH1 = 0xF7;
        TL1 = 0xD0;
        TF1 = 0;
        TR1 = 1;
        while (!TF1) { ; }
    }
    TR1 = 0;
}

// --- Timer0: ISR a ~20 kHz para PWM software ---
// Fsys/12 = 2 MHz ⇒ periodo deseado 20 kHz → 100 ticks
// Reload = 65536 - 100 = 65436 = 0xFF9C
void timer0_isr(void) __interrupt (1) {
    TH0 = 0xFF;
    TL0 = 0x9C;

    // Contador PWM (64 niveles)
    pwm_cnt++;
    if (pwm_cnt >= 64) pwm_cnt = 0;

    // Si LED a VCC→P3.0 (hundiendo corriente): "1" apaga, "0" enciende.
    if (pwm_cnt < duty) {
        // LED encendido → sacar 0
        P3 &= ~(1 << 0);     // P3.0 = 0
    } else {
        // LED apagado → dejar 1 (pull-up)
        P3 |=  (1 << 0);     // P3.0 = 1
    }

    // Si tu LED está P3.0→R→GND (sourcing), invierte arriba:
    // - dentro del if: P3 |=  (1<<0);
    // - en el else:    P3 &= ~(1<<0);
}

static void pwm_init(void) {
    // Opcional: configurar P3.0 como salida push-pull (si tu librería lo permite).
    // En muchos proyectos CH55x:
    //   P3_DIR_PU |= (1<<0);    // salida
    //   P3_MOD_OC &= ~(1<<0);   // push-pull
    // Si no tienes esos registros, el modo cuasi-bidireccional por defecto también funciona
    // con LED a VCC (hundiendo corriente).

    // Timer0 modo 1 (16 bits), interrupción ~20 kHz
    TMOD = (TMOD & 0xF0) | 0x01;   // T0 Modo 1
    TH0  = 0xFF;
    TL0  = 0x9C;
    ET0  = 1;   // habilita int T0
    EA   = 1;   // habilita ints globales
    TR0  = 1;   // arranca T0
}

void main(void) {
    pwm_init();

    // Fade continuo: 0→63 y 63→0
    while (1) {
        for (uint8_t d = 0; d < 64; d++) {
            duty = d;
            delay_ms(10);   // ajusta velocidad del fade
        }
        for (int8_t d = 63; d >= 0; d--) {
            duty = (uint8_t)d;
            delay_ms(10);
        }
    }
}
