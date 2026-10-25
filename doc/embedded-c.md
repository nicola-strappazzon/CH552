# C51 basics

## Program structure

Execution starts in `main`:

```c
void main(void) {
    // Your code here.
    while (1) {
    }
}
```

## Bitwise operators

### OR

Use `|` to set bits.

| A | B | A \| B |
|---|---|---|
| 1 | 0 | 1 |
| 1 | 1 | 1 |
| 0 | 0 | 0 |
| 0 | 1 | 1 |

```c
P3 |= (1 << 0); // Set bit 0.
```

### AND

Use `&` with an inverted mask to clear bits.

| A | B | A & B |
|---|---|---|
| 1 | 0 | 0 |
| 1 | 1 | 1 |
| 0 | 0 | 0 |
| 0 | 1 | 0 |

```c
P3 &= ~(1 << 0); // Clear bit 0.
```

### XOR

Use `^` to toggle bits.

| A | B | A ^ B |
|---|---|---|
| 1 | 0 | 1 |
| 1 | 1 | 0 |
| 0 | 0 | 0 |
| 0 | 1 | 1 |

```c
P3 ^= (1 << 0); // Toggle bit 0.
```

### Shifts and NOT

`1 << n` creates a mask for bit `n`. `>>` shifts right. `~` inverts all bits.

### Assignment and combined masks

These assignments are equivalent:

```c
P3 = P3 | 0x01;
P3 |= 0x01;
```

Combine masks to change several bits:

```c
P3 |= (1 << 0) | (1 << 2) | (1 << 4);
P3 &= ~((1 << 0) | (1 << 2) | (1 << 4));
```

## Conditions

```c
if (BUTTON) {
    LED = 1;
} else {
    LED = 0;
}
```

```c
switch (value) {
    case 0:
        // Handle zero.
        break;
    case 1:
        // Handle one.
        break;
    default:
        // Handle other values.
        break;
}
```
