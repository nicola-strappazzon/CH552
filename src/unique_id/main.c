#include <stdint.h>
#include <stdio.h>
#include "ch552.h"
#include "usb.h"
#include "utils.h"

#define CFG_INFO ((__code const uint8_t *)0x3FF8)

void USBInit(void);
void USBInterrupt(void);
void USB_ISR(void) __interrupt(INT_NO_USB) {
  USBInterrupt();
}

void main(void) {
  init();
  USBInit();

  int counter = 0;
  __xdata char buffer[64]; // Use xRAM and the size is 1K.

  while(1){
    sprintf(buffer,
            "%d - CH552G Unique ID: %02X%02X%02X%02X%02X%02X%02X%02X\r\n",
            counter++,
            CFG_INFO[0], CFG_INFO[1], CFG_INFO[2], CFG_INFO[3],
            CFG_INFO[4], CFG_INFO[5], CFG_INFO[6], CFG_INFO[7]);

    USBWriteString(buffer);

    delay_ms(1000);
  }
}
