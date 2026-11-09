/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:33 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 15:33:18 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

#define BASE10 10
#define	BASE16 16
#define TRUE 1
#define FALSE 0

typedef enum			e_lettercase 
{
	UPPERCASE,
	LOWERCASE
}						t_lettercase;

typedef enum			e_flags
{
	FLAG_LEFT_JUSTIFY,
	FLAG_SIGN,
	FLAG_SPACE,
	FLAG_HASHTAG,
	FLAG_ZERO
}						t_flags;

typedef struct			s_format_specifier
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

typedef union			u_print_value
{
	long int			i;
	unsigned int		u;
	unsigned char		c;
	char 				*s;
	uintptr_t			p;
}						t_print_value;

typedef struct			s_node_contents
{
	char				*substr;
	t_print_value		print_value;
	t_format_specifier	*format_specifier;
	char				*str_to_print;
	int					write_error;
}						t_node_contents;

int				ft_printf(const char *s, ...);

// Output functions
// ssize_t	ft_putaddress_fd(void *ptr);
// ssize_t	ft_puthexnbr_fd(int n, int fd, t_lettercase lettercase);
// ssize_t	ft_putubase_fd(unsigned long int n, 
// 			int fd,
// 			t_lettercase lettercase,
// 			unsigned int base_size);
ssize_t			ft_output(t_format_specifier *f_spec, va_list args);
ssize_t			ft_output_i_d(t_format_specifier *f_spec, va_list args);
ssize_t			ft_output_u(t_format_specifier *f_spec, va_list args);
ssize_t			ft_output_lowx(t_format_specifier *f_spec, va_list args);
ssize_t			ft_output_upx(t_format_specifier *f_spec, va_list args);
ssize_t			ft_output_p(t_format_specifier *f_spec, va_list args);
ssize_t			ft_output_c(t_format_specifier *f_spec, va_list args);
ssize_t			ft_output_s(t_format_specifier *f_spec, va_list args);
ssize_t			ft_putnbr_base_fd(int n, int fd, unsigned int base);
ssize_t			ft_putunbr_fd(unsigned int n,
					int fd,
					unsigned int base,
					t_lettercase lettercase);
ssize_t			ft_putptr_fd(uintptr_t n,
					int fd,
					unsigned int base,
					t_lettercase lettercase);
ssize_t			ft_putsign_fd(int n, int fd, char *flag, char spec);

// Padding functions
ssize_t			ft_write_pad(int pads, char pad);
ssize_t			ft_left_padding_i_d(t_format_specifier *f_spec,
					long int n,
					unsigned int base);
ssize_t			ft_left_padding_u(t_format_specifier *f_spec,
					unsigned int n,
					unsigned int base);
ssize_t			ft_left_padding_x(t_format_specifier *f_spec,
					unsigned long long int n,
					unsigned int base);
ssize_t			ft_left_padding_p(t_format_specifier *f_spec,
					uintptr_t n,
					unsigned int base);
ssize_t			ft_left_padding_c(t_format_specifier *f_spec);
ssize_t			ft_left_padding_s(t_format_specifier *f_spec, char *s);
ssize_t			ft_zero_padding(t_format_specifier *f_spec,
					long int n,
					unsigned int base);
ssize_t			ft_zero_padding_u(t_format_specifier *f_spec,
					unsigned int n,
					unsigned int base);
ssize_t			ft_zero_padding_p(t_format_specifier *f_spec,
					uintptr_t n,
					unsigned int base);
ssize_t			ft_right_padding(t_format_specifier *f_spec, ssize_t nb_char);

// Checks functions
int				ft_isflag(int c);
int				ft_islength(int c);
int				ft_isprecision(int c);
int				ft_isspecifier(int c);
int				ft_iswidth(int c);
int				ft_check_next_spec(int c);

// Utils functions
int				ft_count_digits(long long int n, unsigned int base);
int				ft_count_udigits(unsigned long long int n, unsigned int base);
void			ft_free_format_specifier(t_format_specifier *format_specifier);
char			*ft_getbase(t_lettercase lettercase);
unsigned int		ft_pow(unsigned int n, unsigned int pow);
uintptr_t		ft_pow_ptr(uintptr_t n, unsigned int pow);
int				ft_isneg(long int n);
unsigned int	ft_get_preci_l(t_format_specifier *f_spec);
void			ft_fetch_width_preci(t_format_specifier *f_spec, va_list args);

// Specifier related functions
int				ft_analyse_format_specifier(t_format_specifier *f_spec);
int				ft_extract_number(char *str);
int				ft_get_flag(t_format_specifier *format_specifier);
int				ft_get_length(t_format_specifier *format_specifier);
int				ft_get_precision(t_format_specifier *format_specifier);
int				ft_get_specifier(t_format_specifier *format_specifier);
int				ft_get_width(t_format_specifier *format_spec);
int				ft_init_format_specifier(t_format_specifier *format_specifier, 
					char* str);

// Error related functions
int				ft_error_format_specifier(t_format_specifier *format_specifier);

// strings related functions
int				ft_strcontain(char *str, int c);
char			*ft_extract_format(char *str, int (*check)(int));
char			*ft_extract_subspecifier(char *str, int (*check)(int));

#endif
