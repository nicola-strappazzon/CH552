# Number conversion in Bash

Convert decimal numbers to binary or hexadecimal. The binary function requires `dc`.

```bash
toBin() {
    printf "%08d\n" "$(dc -e "$1 2op")"
}

toHex() {
    printf '%x\n' "$1"
}
```

Example:

```console
$ toBin 10
00001010
$ toHex 10
a
```
