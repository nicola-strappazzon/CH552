# Watchdog

Demonstrates the CH552 hardware watchdog (WDT) by deliberately hanging the MCU and letting the WDT recover it. Uses the same LED on P3.0 as the [blink](/src/blink) example, so any minimal-circuit board will do.

## What you should see

Each reset cycle, what the firmware *intends* to do:

1. **3 boot blinks** (~250 ms on/off) — boot marker. Runs after every reset, so each time it appears you know the chip just restarted.
2. **1 s pause** with the LED off, then the watch-dog is enabled.
3. **4 long blinks** (~500 ms on/off) — healthy phase. The firmware feeds the WDT once at the start of each cycle.
4. **LED on, solid** — simulated hang. The firmware stops feeding the WDT.
5. After ~700 ms the WDT overflows and the chip resets, jumping back to step 1.

### …but what you actually see

With these timings, the healthy phase only completes **about 2 of the 4 long blinks** before the WDT resets the chip. That is not a bug — it is the watchdog doing its job.

Do the math: the WDT timeout is **~700 ms** (preload 0), but each long-blink cycle is 500 ms on + 500 ms off = **1000 ms**, with `watchdog_feed()` called only once per cycle. So between the second feed and the third one, 1000 ms goes by — 300 ms more than the WDT can tolerate. The WDT overflows mid-cycle, resets the chip, and you see the boot marker again before reaching the simulated hang.

In other words: **even "healthy" code gets killed if it goes silent for longer than the timeout window.** That's exactly the point of a watchdog.

If you want all 4 long blinks to complete and only the explicit hang to trigger the reset, you have two clean options:

- Add a second `watchdog_feed()` between the LED on and LED off halves (max gap between feeds drops to 500 ms < 700 ms).
- Shorten the blinks to ~300 ms per half (cycle becomes 600 ms < 700 ms, one feed per cycle is enough).

## How it works on the CH552

- `SAFE_MOD = 0x55; SAFE_MOD = 0xAA;` unlocks `GLOBAL_CFG` for writing.
- `GLOBAL_CFG |= bWDOG_EN;` enables reset-on-overflow (otherwise the WDT is just a free-running 8-bit timer).
- `WDOG_COUNT` increments at Fsys / 65536 (~366 Hz at 24 MHz, so ~2.73 ms per count). Writing any value to it resets the counter — that is the "kick".
- The watch-dog reset clears `GLOBAL_CFG` to its power-on default, so the firmware re-enables the WDT after the boot marker on each cycle.

## Changing the timeout

The CH552 prescaler is **fixed** (Fsys / 65536), so the only knob is the value you load into `WDOG_COUNT` when you feed it. The counter always overflows at 256, so:

```
timeout ≈ (256 − WDOG_COUNT) × 2.73 ms     (at Fsys = 24 MHz)
```

A higher preload means a shorter timeout, because there are fewer counts left until overflow. The example feeds with `0` (maximum timeout). Pick another value to shrink the window:

| Preload | Timeout  |
|--------:|---------:|
|    0    | ~700 ms  |
|  128    | ~349 ms  |
|  200    | ~153 ms  |
|  230    |  ~71 ms  |
|  250    |  ~16 ms  |
