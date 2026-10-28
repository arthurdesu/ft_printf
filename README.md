This project has been created as part of the 42 curriculum by mamehri.

# ft_printf

A from-scratch re-implementation of the C library function `printf`, packaged as a static library (`libftprintf.a`).

## Description

**ft_printf** is a 42 curriculum project. Its goal is to recode `printf()` from `<stdio.h>` (without using it, or any other function of the `printf` family) and to deliver the result as a reusable static library that can be linked into future projects.

**Brief overview**

- `ft_printf` reads a *format string* and writes it to the standard output, replacing each *conversion specifier* (`%c`, `%d`, ...) with the matching extra argument.
- The number and the types of these arguments are unknown in advance, so the function is *variadic* and relies on `<stdarg.h>` (`va_list`, `va_start`, `va_arg`, `va_end`).
- Like the original, it **returns the number of characters printed**.
- Along the way, the project covers: variadic functions, format-string parsing, low-level output with `write(2)`, number-base conversion, and library creation with `ar` and a `Makefile`.

### Prototype

```c
int	ft_printf(const char *format, ...);
```
### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is NULL) |
| `%p` | A `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` if NULL) |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A literal percent sign |

## Instructions

### Compilation

Run the following commands from the root of the repository:

| Command | Effect |
|---------|--------|
| `make` / `make all` | Builds the static library `libftprintf.a` |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and `libftprintf.a` |
| `make re` | Rebuilds everything from scratch (`fclean`, then `all`) |

The sources are compiled with `-Wall -Wextra -Werror`, and the library is archived with `ar`.

### Installation and use in another project

There is nothing to install: copy `libftprintf.a` and `ft_printf.h` into your project (or point the compiler at their location), include the header, and link the library.

Example `main.c`:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s! %d + %i = %u\n", "world", 40, 2, 42);
    ft_printf("hex: %x | HEX: %X | char: %c | percent: %%\n", 255, 255, 'A');
    ft_printf("%d characters were printed on the first line\n", count);
    return (0);
}
```

Build and run:

```bash
make
cc -Wall -Wextra -Werror main.c libftprintf.a
./a.out
```

Output:

```text
Hello, world! 40 + 2 = 42
hex: ff | HEX: FF | char: A | percent: %
26 characters were printed on the first line
```
## Algorithm and data structure

### Chosen algorithm: single-pass scan with specifier dispatch

`ft_printf` behaves like a very small interpreter of its format string:

1. `va_start` initialises a `va_list` positioned right after the last named parameter (`format`).
2. The format string is scanned **once, from left to right**, one character at a time.
3. A character other than `%` is a literal: it is written as is and counted.
4. A `%` introduces a conversion: the character that follows (the *specifier*) selects the handler to call.
5. The handler reads its argument with `va_arg`, using the type implied by the specifier, writes the result, and **returns the number of characters it wrote**.
6. The counts are accumulated; at the end of the string, `va_end` is called and the total is returned.

Notes:

- **`%c` reads an `int`**: `char` and `short` arguments undergo the default argument promotions to `int` when passed through `...`, so asking `va_arg` for a `char` would be undefined behaviour.
- **NULL handling**: a NULL string or pointer is handled explicitly. This avoids dereferencing a null pointer and mirrors the output of glibc (`(null)` / `(nil)`).
- **`%p`**: the pointer is converted to an unsigned integer wide enough to hold an address (`unsigned long`) and printed in base 16 after `0x`.
- **`%u`, `%x`, `%X`** read an `unsigned int`, so values above `INT_MAX` are printed correctly.

### Number conversion: recursive digit printing

Integers are printed by a recursive routine parameterised by the base and by a lookup string of digits (`"0123456789"`, `"0123456789abcdef"`, `"0123456789ABCDEF"`):

## Resources

### Classic references

- [`printf(3)`, Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [`stdarg(3)`, Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html): variable argument lists
- [`write(2)`, Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)

## AI Usage

AI was used as an assistant throughout the project to clarify concepts, suggest test cases, explain errors. All code was reviewed and understood by me, and the final implementation and technical decisions remained my responsibility.
