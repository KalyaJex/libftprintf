*This project has been created as part of the 42 curriculum by svannay.*
# Printf

## Description

Printf description

## Instructions

### Compilation

Clone the repository and build the library with `make`:

```bash
git clone <repository-url> libftprintf
cd libftprintf
make
```

The following Makefile targets are available:

| Target | Action |
| ------ | ------ |
| `make` / `make all` | Build `libftprintf.a` |
| `make bonus` | Build `libftprintf.a` including the linked list functions |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libftprintf.a` |
| `make re` | Rebuild everything from scratch |

The library is compiled with `-Wall -Wextra -Werror`.

### Usage

Include the header in your source files:

```c
#include "libftprintf.h"
```

Then compile your program and link it against the library:

```bash
cc my_program.c -I<path_to_libftprintf> -L<path_to_libftprintf> -lftprintf -o my_program
```

- `-I` tells the compiler where to find `libftprintf.h`.
- `-L` tells the linker where to find `libftprintf.a`.
- `-lftprintf` links `libftprintf.a` (the `lib` prefix and the `.a` extension are implied).

For example, if `libftprintf.a` and `libftprintf.h` are in the current folder:

```bash
cc my_program.c -I. -L. -lftprintf -o my_program
```

## Functions



F

### References

- [How to tell your compiler that you have implemented printf-like functions](https://dev.to/martinlicht/how-to-tell-your-compiler-that-you-have-implemented-printf-like-functions-2bfp)


### Use of AI

Claude (by Anthropic) was used to review and proofread this README: it helped identify typos and inaccurate function descriptions, and suggested a clearer structure and formatting. The library code itself was written by the author.

- Use of Claude asking about C variadic functions compile-time type checking.
- Use of Claude asking about Inheriting struct properties in C
- Use of Claude asking about Void pointer return type in C