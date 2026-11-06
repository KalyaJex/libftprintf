/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:33 by svannay           #+#    #+#             */
/*   Updated: 2026/11/06 13:38:18 by svannay          ###   ########.fr       */
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

int		ft_printf(const char *s, ...);

// Checks functions
int		ft_isflag(int c);
int		ft_islength(int c);
int		ft_isprecision(int c);
int		ft_isspecifier(int c);
int		ft_iswidth(int c);
int		ft_check_next_spec(int c);

// Utils functions
int		ft_count_digits(long long int n, unsigned int base);
int		ft_count_udigits(unsigned long long int n, unsigned int base);
void	ft_free_format_specifier(t_format_specifier *format_specifier);
void	ft_free_node_content(void *content);
char	*ft_getbase(t_lettercase lettercase);
char	*ft_free_all(unsigned int n, ...);

// Specifier related functions
int		ft_analyse_format_specifier(t_format_specifier *format_specifier);
int		ft_extract_number(char *str);
int		ft_get_flag(t_format_specifier *format_specifier);
int		ft_get_length(t_format_specifier *format_specifier);
int		ft_get_precision(t_format_specifier *format_specifier);
int		ft_get_specifier(t_format_specifier *format_specifier);
int		ft_get_width(t_format_specifier *format_spec);
int		ft_init_format_specifier(t_format_specifier *format_specifier, 
			char* str);

// Output functions
// ssize_t	ft_putaddress_fd(void *ptr);
// ssize_t	ft_puthexnbr_fd(int n, int fd, t_lettercase lettercase);
// ssize_t	ft_putubase_fd(unsigned long int n, 
// 			int fd,
// 			t_lettercase lettercase,
// 			unsigned int base_size);
ssize_t	ft_putnbr_fd(int n, int fd, unsigned int base);
ssize_t	ft_putunbr_fd(unsigned int n,
			int fd,
			unsigned int base,
			t_lettercase lettercase);
ssize_t	ft_putsign_fd(int n, int fd, char flag, char spec);

// Node content related functions
int		ft_fill_node(t_list **list, char *next, char *substr, va_list args);
int		ft_get_arg(t_node_contents *node, va_list args);
int		ft_init_node(t_node_contents *node, char *str, va_list args);
char	*ft_splitter(t_node_contents *node);
t_list	*ft_process_args(va_list args, char *s);
char	*ft_create_str(t_node_contents *node);

// Error related functions
int		ft_error_fill_node(t_list **list);
int		ft_error_format_specifier(t_format_specifier *format_specifier);
int		ft_error_init_node(t_node_contents *node);

// Convertion functions
char	*ft_add_zero(char *str);
char	*ft_ctos(char c);
char	*ft_itoa(int n, unsigned int base, t_lettercase lettercase);
char	*ft_ltoa(long int ln, unsigned int base, t_lettercase lettercase);
char	*ft_utoa(unsigned int n, unsigned int base, t_lettercase lettercase);
char	*ft_ultoa(unsigned long int ln, unsigned int base, t_lettercase lettercase);

// Linked list functions
size_t	ft_lstsum(t_list *list, size_t (*getlen)(void *));
size_t	ft_get_strlen(void *content);

// strings related functions
int		ft_strcontain(char *str, int c);
char	*ft_extract_format(char *str, int (*check)(int));
char	*ft_strinsert(char *dest, char *src, unsigned int pos);
char	*strndup(const char *s, size_t n);
char	*ft_extract_subspecifier(char *str, int (*check)(int));

#endif
