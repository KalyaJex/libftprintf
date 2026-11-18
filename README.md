
*This project has been created as part of the 42 curriculum by svannay.*
 
# ft_printf
 
## Description
 
`ft_printf` recreates the behavior of the libc `printf` function. It is built as a static library (`libftprintf.a`) and supports the following conversions:
 
| Conversion | Output |
| ---------- | ------ |
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A literal percent sign |
 
Flags, width, precision and length modifiers are not implemented. They are parsed but ignored, and the argument is printed as if they were absent. For example, `ft_printf("%5d", 42)` prints `42`.
 
Special cases:
 
- `%s` with a `NULL` string prints `(null)`.
- `%p` with a `NULL` pointer prints `(nil)`.
- An invalid specifier is printed as-is instead of an argument.
Like `printf`, `ft_printf` returns the number of characters written, or `-1` if an error occurred.
 
### Data structures
 
The data extracted from a format specifier is stored in a `t_format_specifier` struct:
 
```c
typedef struct s_format_specifier
{
	char				*format;
	char				*og_ptr;
	char				*flag;
	unsigned int		width;
	char				width_flag;
	unsigned int		precision;
	char				precision_flag;
	char				*length;
	char				specifier;
	int					is_gibberish;
}						t_format_specifier;
```
 
The parser already extracts flags, width, precision and length modifiers, but the output functions do not use them yet, because the bonus part was not implemented. These fields are kept so that it can be added later.
 
| Field | Description |
| ----- | ----------- |
| `format` | The extracted specifier string |
| `og_ptr` | A pointer to the start of `format`. It is used to print the specifier when it is gibberish, and to free the string, since `format` itself may have moved during parsing |
| `specifier` | The conversion character (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` or `%`) |
| `is_gibberish` | Raised when the specifier is invalid. The specifier is then printed as-is instead of an argument |
| `flag` | The flags of the specifier (unused) |
| `width` | The width of the specifier (unused) |
| `width_flag` | How the width is given (unused), see below |
| `precision` | The precision of the specifier (unused) |
| `precision_flag` | How the precision is given (unused), see below |
| `length` | The length modifier of the specifier (unused) |
 
`width_flag` can take the following values:
 
| Value | Meaning |
| ----- | ------- |
| `'\0'` | No width in the specifier |
| `'*'` | Width taken from an argument (`%*d`) |
 
`precision_flag` can take the following values:
 
| Value | Meaning |
| ----- | ------- |
| `'\0'` | No precision in the specifier |
| `'.'` | Precision given in the specifier (`%.3d`) |
| `'*'` | Precision taken from an argument (`%.*d`) |
| `'0'` | Explicit zero precision, to tell it apart from no precision |
 
The number of characters written so far and an error flag are stored in a `t_char_count` struct:
 
```c
typedef struct s_char_count
{
	ssize_t			nb;
	int				error;
}					t_char_count;
```
 
- `nb` is the number of characters written.
- `error` is set to `-1` when a call to `write` fails.
### Algorithm
 
1. `ft_printf` initializes a `t_char_count` to track the number of characters written and any error.
2. `process_str` loops through the format string and writes every character until it meets a `%`.
3. At a `%`, the specifier is parsed one subspecifier at a time into a `t_format_specifier`. Flags, width, precision and length are extracted but not used afterwards.
4. If the specifier is gibberish, a flag is raised and the specifier text is printed instead of an argument.
5. Otherwise, the argument is fetched with `va_arg` by the matching output function and written to standard output, ignoring flags, width, precision and length. `t_char_count` is updated as characters are written.
6. Errors are propagated upward. Once an error is raised, every output function short-circuits so that nothing more is printed, and `-1` is returned.
7. When the current specifier has been handled, its `t_format_specifier` is freed.
8. When the whole string has been processed, the total is read from `t_char_count`, which is then freed, and the total is returned.
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
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libftprintf.a` |
| `make re` | Rebuild everything from scratch |
 
The library is compiled with `-Wall -Wextra -Werror`.
 
### Usage
 
Include the header in your source files:
 
```c
#include "ft_printf.h"
```
 
Then compile your program and link it against the library:
 
```bash
cc my_program.c -I<path_to_libftprintf> -L<path_to_libftprintf> -lftprintf -o my_program
```
 
- `-I` tells the compiler where to find the header.
- `-L` tells the linker where to find `libftprintf.a`.
- `-lftprintf` links `libftprintf.a` (the `lib` prefix and the `.a` extension are implied).
For example, if `libftprintf.a` and the header are in the current folder:
 
```bash
cc my_program.c -I. -L. -lftprintf -o my_program
```
 
A minimal program:
 
```c
#include "ft_printf.h"
 
int	main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "Sam", 42);
	return (0);
}
```
 
Expected output:
 
```
Hello Sam, you are 42 years old
```
 
## Resources
 
### References
 
- [How to tell your compiler that you have implemented printf-like functions](https://dev.to/martinlicht/how-to-tell-your-compiler-that-you-have-implemented-printf-like-functions-2bfp)
- [printf reference](https://cplusplus.com/reference/cstdio/printf/)
- `man 3 printf`
- `man 3 stdarg`
### Use of AI
 
Claude (by Anthropic) was used as a learning and debugging aid, and to review and proofread this README. It was used for:
 
- Questions about compile-time type checking of C variadic functions.
- Questions about inheriting struct properties in C.
- Questions about void pointer return types in C.
- Questions about format specifier parsing in `printf`.
- Analyzing valgrind errors.
- Reviewing this README for typos, inaccuracies and structure.
The implementation itself was written by the author.
 
