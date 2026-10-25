# Watchdog

## Description

Stop feeding the hardware watchdog to trigger a reset.

## Schematic

No example schematic is included. See the [minimum circuit](/README.md#minimum-circuit).

## Features

- LED on P3.0.
- Three short startup blinks, followed by a pause.
- Four longer blinks while feeding the watchdog.
- Stops feeding after the blink sequence.

## Additional information

The sequence repeats after a watchdog reset. `watchdog_enable()` unlocks `GLOBAL_CFG` and sets `bWDOG_EN`. `watchdog_feed()` writes zero to `WDOG_COUNT`.

The timeout depends on the system clock and preload:

```text
timeout = (256 - preload) × 65536 / Fsys
```

Keep the interval between feeds below the timeout. A higher preload gives a shorter timeout; this example uses zero.
