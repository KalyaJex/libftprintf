/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:33 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:21:20 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BASE10 10
# define BASE16 16

typedef enum e_lettercase
{
	UPPERCASE,
	LOWERCASE
}						t_lettercase;

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

int				ft_printf(const char *s, ...);

// Output functions
t_char_count	*ft_output(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count);
t_char_count	*ft_output_i_d(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count);
t_char_count	*ft_output_u(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count);
t_char_count	*ft_output_lowx(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count);
t_char_count	*ft_output_upx(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count);
t_char_count	*ft_output_p(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count);
t_char_count	*ft_output_c(va_list args, t_char_count *char_count);
t_char_count	*ft_output_s(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count);
t_char_count	*ft_putnbr_base(int n,
					unsigned int base,
					t_char_count *char_count);
t_char_count	*ft_putunbr(unsigned int n,
					unsigned int base,
					t_lettercase lettercase,
					t_char_count *char_count);
t_char_count	*ft_putptr(uintptr_t n,
					unsigned int base,
					t_lettercase lettercase,
					t_char_count *char_count);
t_char_count	*ft_putsign(int n,
					t_format_specifier *f_spec,
					t_char_count *char_count);
t_char_count	*ft_putprefix(uintptr_t n,
					t_format_specifier *f_spec,
					t_char_count *char_count);
t_char_count	*ft_putnstr(char *s, unsigned int n, t_char_count *char_count);

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
void			ft_free_format_spec(t_format_specifier *format_specifier);
char			*ft_getbase(t_lettercase lettercase);
unsigned int	ft_pow(unsigned int n, unsigned int pow);
uintptr_t		ft_pow_ptr(uintptr_t n, unsigned int pow);
int				ft_isneg(long int n);
unsigned int	ft_get_preci_l(t_format_specifier *f_spec);
void			ft_fetch_width_preci(t_format_specifier *f_spec, va_list args);
int				ft_count_digit_space(long long int n, unsigned int base,
					t_format_specifier *f_spec);
void			ft_init_char_count(t_char_count **char_count);
int				ft_max(int a, int b);

// Specifier related functions
int				ft_analyse_format_specifier(t_format_specifier *f_spec);
int				ft_extract_number(char *str);
int				ft_get_flag(t_format_specifier *format_specifier);
int				ft_get_length(t_format_specifier *format_specifier);
int				ft_get_precision(t_format_specifier *format_specifier);
int				ft_get_specifier(t_format_specifier *format_specifier);
int				ft_get_width(t_format_specifier *format_spec);
int				ft_init_format_specifier(t_format_specifier *format_specifier,
					char *str);

// Error related functions
void			ft_error_format_specifier(t_format_specifier *format_specifier,
					t_char_count *char_count);

// strings related functions
int				ft_strcontain(char *str, int c);
char			*ft_extract_format(char *str, int (*check)(int));
char			*ft_extract_subspecifier(char *str, int (*check)(int));

#endif
