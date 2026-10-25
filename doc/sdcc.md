# SDCC

[SDCC](https://sdcc.sourceforge.net) is a free C compiler for 8-bit microcontrollers.

## Installation

Debian or Ubuntu:

```bash
sudo apt install build-essential sdcc binutils
```

macOS:

```bash
brew install sdcc binutils
```

Add GNU binutils to your shell profile on macOS:

```bash
export PATH="$(brew --prefix binutils)/bin:$PATH"
```

Reload the profile or open a new terminal. If `make` reports `objcopy: No such file or directory`, check this path.

## Build

From the repository root:

```bash
make -C src/blink
```

The example Makefiles share compiler settings in `src/Makefile.include`. They produce `.bin` and `.hex` files.

See [Flash firmware](flash.md) for upload instructions.
