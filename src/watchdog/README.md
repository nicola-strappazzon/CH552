# Watchdog

Demonstrates the CH552 hardware watchdog (WDT) by deliberately hanging the MCU and letting the WDT recover it. Uses the same LED on P3.0 as the [blink](/src/blink) example, so any minimal-circuit board will do.

## What you should see

Each reset cycle looks like this:

1. **3 fast blinks** (~150 ms on/off) — boot marker. This runs after every reset, so each time it appears you know the chip just restarted.
2. **4 slow blinks** (~250 ms on/off) — healthy phase. The watch-dog is enabled and the firmware is feeding it on every cycle.
3. **LED on, solid** — simulated hang. The firmware stops feeding the watch-dog.
4. After ~700 ms the WDT overflows and the chip resets, jumping back to step 1.

If you remove the `watchdog_feed()` call from inside the slow-blink loop, the chip resets mid-sequence — proof that without the kick, even healthy code gets killed.

## How it works on the CH552

- `SAFE_MOD = 0x55; SAFE_MOD = 0xAA;` unlocks `GLOBAL_CFG` for writing.
- `GLOBAL_CFG |= bWDOG_EN;` enables reset-on-overflow (otherwise the WDT is just a free-running 8-bit timer).
- `WDOG_COUNT` increments at Fsys / 65536 (~366 Hz at 24 MHz, so ~2.73 ms per count). Writing any value to it resets the counter — that is the "kick".
- Full timeout from a fresh kick: 256 × 2.73 ms ≈ **700 ms**.
- The watch-dog reset clears `GLOBAL_CFG` to its power-on default, so the firmware re-enables the WDT after the boot marker on each cycle.
