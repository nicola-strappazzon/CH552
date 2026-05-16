#include <ch552.h>
#include <utils.h>

SBIT(P30, 0xB0, 0);

#define LED P30

static void watchdog_enable(void) {
  SAFE_MOD    = 0x55;
  SAFE_MOD    = 0xAA;
  GLOBAL_CFG |= bWDOG_EN;
  WDOG_COUNT  = 0;
}

static void watchdog_feed(void) {
  WDOG_COUNT = 0;
}

void main(void) {
  unsigned char i;

  init();

  P3_MOD_OC &= ~(1 << 0);
  P3_DIR_PU |=  (1 << 0);

  // Boot marker: 3 fast blinks after every reset. If you see this pattern
  // repeating, the watch-dog is rescuing a hung MCU.
  for(i = 0; i < 3; i++) {
    LED = 1; delay_ms(100);
    LED = 0; delay_ms(100);
  }
  delay_ms(1000);

  watchdog_enable();

  // Healthy phase: feed the watch-dog on every blink cycle.
  for(i = 0; i < 4; i++) {
    watchdog_feed();
    LED = 1; delay_ms(250);
    LED = 0; delay_ms(250);
  }

  // Simulated hang: LED on, watch-dog no longer fed. ~700 ms later the WDT
  // overflows, the MCU resets, and the boot marker fires again.
  LED = 1;
  while(1);
}
