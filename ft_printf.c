/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:29 by svannay           #+#    #+#             */
/*   Updated: 2026/11/06 16:55:19 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: fix compilation errors

#include "libftprintf.h"
#include <stdio.h>

// int	ft_count_digits(long int n)
// {
// 	int			count;
// 	int			is_negative;

// 	is_negative = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 	{
// 		is_negative = 1;
// 		n *= -1;
// 	}
// 	count = 0;
// 	while (0 < n)
// 	{
// 		n /= 10;
// 		count++;
// 	}
// 	return (count + is_negative);
// }

// int	ft_isspecifier(int c)
// {
// 	if (!c || !ft_strchr("cspdiuxX%", c))
// 		return (0);
// 	return (1);
// }

// int	ft_isflag(int c)
// {
// 	if (!ft_strchr("-+ #0", c))
// 		return (0);
// 	return (1);
// }

// int	ft_isprecision(int c)
// {
// 	return (c == '.');
// }

// int	ft_islength(int c)
// {
// 	if (!ft_strchr("hljztL", c))
// 		return (0);
// 	return (1);
// }

// char	*ft_extract_format_specifier(char *str)
// {
// 	unsigned int	count;
	
// 	count = 0;
// 	while(*str)
// 	{
// 		if (ft_isspecifier(*str))
// 			break ;
// 		str++;
// 		count++;
// 	}
// 	return (ft_substr(str, 0, count + 1));
// }

// int	ft_extract_number(char *str)
// {
// 	unsigned int	count;
// 	char			*number;
// 	int				result;
// 	count = 0;
// 	while(ft_isdigit(*str))
// 	{
// 		str++;
// 		count++;
// 	}
// 	number = ft_substr(str, 0, count);
// 	result = ft_atoi(number);
// 	free(number);
// 	return (result);
// }

// void	ft_get_flag(t_format_specifier *format_specifier)
// {
// 	while (ft_isflag(*(format_specifier->format)))
// 	{
// 		if (!format_specifier->flag)
// 			format_specifier->flag = *(format_specifier->format);
// 		(format_specifier->format)++;
// 	}
// }

// void	ft_get_width(t_format_specifier *format_specifier)
// {
// 	while (ft_isdigit(*(format_specifier->format))
// 		|| *(format_specifier->format) == '*')
// 	{
// 		if (*(format_specifier->format) == '*')
// 		{
// 			format_specifier->width_flag = '*';
// 			(format_specifier->format)++;
// 			return ;
// 		}
// 		format_specifier->width = ft_extract_number(format_specifier->format);
// 		format_specifier->format += ft_count_digits(format_specifier->width);
// 	}
// }

// void	ft_get_precision(t_format_specifier *format_specifier)
// {
// 	if (ft_isprecision(*(format_specifier->format)))
// 	{
// 		if (*(format_specifier->format + 1) == '*')
// 		{
// 			format_specifier->precision_flag = '*';
// 			(format_specifier->format) += 2;
// 			return;
// 		}
// 		format_specifier->precision = ft_extract_number((format_specifier->format) + 1);
// 		(format_specifier->format) += ft_count_digits(format_specifier->precision) + 1;
// 	}
// }

// void	ft_get_length(t_format_specifier *format_specifier)
// {
// 	while (ft_islength(*(format_specifier->format)))
// 	{
// 		if (*(format_specifier->format) == format_specifier->length)
// 			format_specifier->is_length_flag_double = 1;
// 		else
// 			format_specifier->length = *(format_specifier->format);
// 		(format_specifier->format)++;
// 	}
// }

// void	ft_get_specifier(t_format_specifier *format_specifier)
// {
// 	while (ft_isspecifier(*(format_specifier->format)))
// 	{
// 		format_specifier->specifier = *(format_specifier->format);
// 		(format_specifier->format)++;
// 	}
// }

// int	ft_analyse_format_specifier(t_format_specifier *format_specifier)
// {
// 	ft_get_flag(format_specifier);
// 	ft_get_width(format_specifier);
// 	ft_get_precision(format_specifier);
// 	ft_get_length(format_specifier);
// 	ft_get_specifier(format_specifier);
// 	if (!*format_specifier->format)
// 		return (0);
// 	return (-1);
// }

// void	ft_splitter(va_list args, char c)
// {
// 	intptr_t	*ptr;
	
// 	if (c == '%')
// 		ft_putchar_fd('%', 1);
// 	else if (c == 'c')
// 		ft_putchar_fd(va_arg(args, int), 1);
// 	else if (c == 's')
// 		ft_putstr_fd(va_arg(args, char *), 1);
// 	else if (c == 'p')
// 	{
// 		ptr = va_arg(args, void *);
// 		ft_putaddress_fd(ptr);
// 	}
// 	else if (c == 'd' || c == 'i')
// 		ft_putnbr_fd(va_arg(args, int), 1);
// 	else if (c == 'u')
// 		ft_putubase_fd(va_arg(args, int), 1, LOWERCASE, 10);
// 	else if (c == 'x')
// 		ft_puthexnbr_fd(va_arg(args, int), 1, LOWERCASE);
// 	else if (c == 'X')
// 		ft_puthexnbr_fd(va_arg(args, int), 1, UPPERCASE);
// }

// int ft_get_arg(t_node_contents *node, va_list args)
// {
// 	char	c;

// 	c = node->format_specifier->specifier;
// 	if (c == '%')
// 	{
// 		node->print_value.c = '%';
// 		return (0);
// 	}
// 	if (c == 'c')
// 		node->print_value.c = (char)va_arg(args, int);
// 	else if (c == 's')
// 	{
// 		node->print_value.s = ft_strdup(va_arg(args, char *));
// 		if (!node->print_value.s)
// 			return (-1);
// 	}
// 	else if (c == 'p')
// 		node->print_value.p = va_arg(args, void *);
// 	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
// 		node->print_value.i = va_arg(args, int);
// 	return (0);
// }

// t_value_type	ft_get_type(char c)
// {
// 	if (c == '%')
// 		return (TYPE_PERCENT);
// 	else if (c == 'c')
// 		return (TYPE_CHAR);
// 	else if (c == 's')
// 		return (TYPE_STR);
// 	else if (c == 'p')
// 		return (TYPE_PTR);
// 	else if (c == 'd')
// 		return (TYPE_DINT);
// 	else if (c == 'i')
// 		return (TYPE_INT);
// 	else if (c == 'u')
// 		return (TYPE_UINT);
// 	else if (c == 'x')
// 		return (TYPE_LOWX);
// 	else if (c == 'X')
// 		return (TYPE_UPX);
// 	return (TYPE_UNDEFINED);
// }

void	ft_print_node(void *content)
{
	t_format_specifier	*format_specifier;

	format_specifier = ((t_node_contents *)content)->format_specifier;
	//printf("|%s| |%s|\n", ((t_node_contents *)content)->substr, ((t_node_contents *)content)->str_to_print);
	if (ft_putstr_fd(((t_node_contents *)content)->substr, 1) < 0)
		((t_node_contents *)content)->write_error = TRUE;
	if (((t_node_contents *)content)->str_to_print)
	{
		if (ft_putstr_fd(((t_node_contents *)content)->str_to_print, 1) < 0)
			((t_node_contents *)content)->write_error = TRUE;
	}
	else if (format_specifier && format_specifier->specifier == 'c')
	{
		if (ft_putchar_fd(((t_node_contents *)content)->print_value.c, 1) < 0)
			((t_node_contents *)content)->write_error = TRUE;
	}
	//ft_splitter(args, ((t_node_contents *)content)->type_value);
}

// void	ft_free_format_specifier(t_format_specifier *format_specifier)
// {
// 	if (format_specifier->og_ptr)
// 		free(format_specifier->og_ptr);
// 	free(format_specifier);
// }

// int	ft_init_format_specifier(t_format_specifier *format_specifier, char* str)
// {
// 	int	error;
// 	int	format_specifier_l;

// 	error = 0;
// 	format_specifier->format = ft_extract_format_specifier(str);
// 	format_specifier->og_ptr = format_specifier->format;
// 	format_specifier_l = (int)ft_strlen(format_specifier->format);
// 	if (!format_specifier->format)
// 		return (-1);
// 	format_specifier->flag = 0;
// 	format_specifier->width = 0;
// 	format_specifier->width_flag = 0;
// 	format_specifier->is_length_flag_double = 0;
// 	format_specifier->length = 0;
// 	format_specifier->precision = 0;
// 	format_specifier->precision_flag = 0;
// 	format_specifier->specifier = 0;
// 	error += ft_analyse_format_specifier(format_specifier);
// 	if (error < 0)
// 	{
// 		ft_free_format_specifier(format_specifier);
// 		return (-1);
// 	}
// 	return (format_specifier_l);
// }

// void	ft_free_node_content(void *content)
// {
// 	if (((t_node_contents *)content)->format_specifier)
// 		ft_free_format_specifier(((t_node_contents *)content)->format_specifier);
// 	//printf("CHECK %s\n", ((t_node_contents *)content)->substr);
// 	free(((t_node_contents *)content)->substr);
	
// 	if (content)
// 	{
// 		//printf("CHECK %s\n", ((t_node_contents *)content)->substr);
// 		free(content);
// 	}
// }

// int	ft_error_format_specifier(t_format_specifier *format_specifier)
// {
// 	ft_free_format_specifier(format_specifier);
// 	return (-1);
// }

// int	ft_error_init_node(t_node_contents *node)
// {
// 	ft_free_node_content(node);
// 	return (-1);
// }

// int	ft_error_fill_node(t_list **list)
// {
// 	if (*list)
// 		ft_lstclear(list, ft_free_node_content);
// 	return (-1);
// }

// int	ft_init_node(t_node_contents *node, char *str, va_list args)
// {
// 	t_format_specifier	*format_specifier;
// 	int			format_specifier_l;

// 	format_specifier_l = 0;
// 	format_specifier = (t_format_specifier *)malloc(sizeof(t_format_specifier));
// 	if (!format_specifier)
// 		return (-1);
// 	format_specifier_l = ft_init_format_specifier(format_specifier, str);
// 	if (0 > format_specifier_l)
// 		return (ft_error_format_specifier(format_specifier));
// 	node->format_specifier = format_specifier;
// 	node->substr = str;
// 	if (0 > ft_get_arg(node, args))
// 		return (ft_error_init_node(node));
// 	if (node->format_specifier->width_flag)
// 		node->format_specifier->width = va_arg(args, int);
// 	if (node->format_specifier->precision_flag)
// 		node->format_specifier->precision = va_arg(args, int);
// 	return (format_specifier_l);
// }

// int	ft_fill_node(t_list **list, char *next, char *substr, va_list args)
// {
// 	t_node_contents	*node_content;
// 	t_list			*node;
// 	int				format_specifier_l;

// 	node = NULL;
// 	format_specifier_l = 0;
// 	node_content = (t_node_contents *)malloc(sizeof(t_node_contents));
// 	if (!node_content)
// 		return (ft_error_fill_node(list));
// 	if (!*next)
// 		node_content->format_specifier = NULL;
// 	else
// 	{
// 		format_specifier_l = ft_init_node(node_content, next, args);
		
// 	}
// 	if (0 > format_specifier_l)
// 		return (ft_error_fill_node(list));
// 	node_content->substr = substr;
// 	node = ft_lstnew(node_content);
// 	if (!node)
// 		return (ft_error_fill_node(list));
// 	ft_lstadd_back(list, node);
// 	return (format_specifier_l);
// }

// t_list	*ft_process_args(va_list args, char *s)
// {
// 	t_list	*list;
// 	char	*next;
// 	int		length;

// 	list = NULL;
// 	length = 0;
// 	while (1)
// 	{
// 		next = ft_strchr(s, '%');
// 		if (!next)
// 		{
// 			ft_fill_node(&list,
// 							"",
// 							ft_substr(s, length, ft_strlen((char *)s)),
// 							args);
// 			break ;
// 		}
// 		length = ft_fill_node(&list, next + 1, ft_substr(s, length, next - s), args);
// 		if (0 > length)
// 			return (NULL);
// 		s = next + length + 1;
// 	}
// 	return (list);
	
// }

int	ft_isneg(long int n)
{
	return (n < 0);
}

ssize_t	ft_write_pad(int pads, char pad)
{
	int		index;
	ssize_t	nb_char;
	ssize_t	err;

	index = 0;
	while (index < pads)
	{
		err = write(1, &pad, 1);
		if (err < 0)
			return (-1);
		nb_char += err;
	}
	return (nb_char);
}

unsigned int	ft_get_preci_l(t_format_specifier *f_spec)
{
	if (!f_spec->precision_flag || f_spec->precision_flag == '0')
		return (0);
	return (f_spec->precision);
}

ssize_t	ft_left_padding(t_format_specifier *f_spec, long int n, unsigned int base)
{
	int		nb_digit;
	ssize_t	err;
	char	pad;

	nb_digit = ft_count_digits(n, base);
	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	if (!ft_isneg(n) && ft_strcontain(f_spec->flag, '0') && !f_spec->precision_flag)
		pad = '0';
	else
		pad = ' ';
	if (f_spec->precision_flag == '0' && n == 0)
		err = ft_write_pad(f_spec->width, pad);
	else if (ft_isneg(n) && !f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit - 1, pad);
	else if (!f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, pad);
	else if (ft_isneg(n) && ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec) - 1, pad);
	else if (ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec), pad);
	return (err);
}

ssize_t	ft_left_upadding(t_format_specifier *f_spec, unsigned long int n, unsigned int base)
{
	int		nb_digit;
	ssize_t	err;
	char	pad;

	nb_digit = ft_count_udigits(n, base);
	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	if (ft_strcontain(f_spec->flag, '0') && !f_spec->precision_flag)
		pad = '0';
	else
		pad = ' ';
	if (f_spec->precision_flag == '0' && n == 0)
		err = ft_write_pad(f_spec->width, pad);
	else if (!f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, pad);
	else if (ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec), pad);
	return (err);
}

ssize_t	ft_left_xpadding(t_format_specifier *f_spec, unsigned long long int n, unsigned int base)
{
	int		nb_digit;
	ssize_t	err;
	char	pad;
	int		need_prefix;

	need_prefix = ft_strcontain(f_spec->flag, '#');
	nb_digit = ft_count_udigits(n, base);
	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	if (ft_strcontain(f_spec->flag, '0') && !f_spec->precision_flag)
		pad = '0';
	else
		pad = ' ';
	if (f_spec->precision_flag == '0' && n == 0)
		err = ft_write_pad(f_spec->width, pad);
	else if (need_prefix && !f_spec->precision_flag && (nb_digit + 2) < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit - 2, pad);
	else if (!f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, pad);
	else if (need_prefix && ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec) - 2, pad);
	else if (ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec), pad);
	return (err);
}

ssize_t	ft_zero_padding(t_format_specifier *f_spec, long int n, unsigned int base)
{
	ssize_t	err;
	int		nb_digit;

	err = 0;
	nb_digit = ft_count_digits(n, base);
	if (ft_isneg(n) && f_spec->precision)
		err = ft_write_pad(f_spec->precision - nb_digit + 1, '0');
	else if (f_spec->precision)
		err = ft_write_pad(f_spec->precision - nb_digit, '0');
	else if (ft_isneg(n) && f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, '0');
	return (err);
}

ssize_t	ft_zero_upadding(t_format_specifier *f_spec, long int n, unsigned int base)
{
	ssize_t	err;
	int		nb_digit;

	err = 0;
	nb_digit = ft_count_udigits(n, base);
	if (f_spec->precision)
		err = ft_write_pad(f_spec->precision - nb_digit, '0');
	return (err);
}

ssize_t	ft_right_padding(t_format_specifier *f_spec, ssize_t nb_char)
{
	ssize_t	err;

	err = 0;
	if (ft_strcontain(f_spec->flag, '-'))
		err = ft_write_pad(f_spec->width - nb_char, ' ');
	return (err);
}

ssize_t	ft_output_i_d(t_format_specifier *f_spec, va_list args)
{
	long int	n;
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	n = (long int)va_arg(args, long int);
	if (ft_isneg(err = ft_left_padding(f_spec, n, BASE10)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_putsign_fd(n, 1, f_spec->flag, f_spec->specifier)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_zero_padding(f_spec, n, BASE10)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_putnbr_fd(n, 1, BASE10)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_right_padding(f_spec, nb_char)))
		return (-1);
	nb_char += err;
	return (nb_char);
}

ssize_t	ft_output_u(t_format_specifier *f_spec, va_list args)
{
	long int	n;
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	n = (long int)va_arg(args, long int);
	if (ft_isneg(err = ft_left_upadding(f_spec, n, BASE10)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_zero_upadding(f_spec, n, BASE10)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_putunbr_fd(n, 1, BASE10, LOWERCASE)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_right_padding(f_spec, nb_char)))
		return (-1);
	nb_char += err;
	return (nb_char);
}

ssize_t	ft_output_x(t_format_specifier *f_spec, va_list args)
{
	long int	n;
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	n = (long int)va_arg(args, long int);
	if (ft_isneg(err = ft_left_xpadding(f_spec, n, BASE16)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_putsign_fd(n, 1, f_spec->flag, f_spec->specifier)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_zero_upadding(f_spec, n, BASE16)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_putunbr_fd(n, 1, BASE16, LOWERCASE)))
		return (-1);
	nb_char += err;
	if (ft_isneg(err = ft_right_padding(f_spec, nb_char)))
		return (-1);
	nb_char += err;
	return (nb_char);
}

void	ft_fetch_width(t_format_specifier *f_spec, va_list args)
{
	if (f_spec->width_flag == '*')
		f_spec->width = va_arg(args, int);
}

void	ft_fetch_preci(t_format_specifier *f_spec, va_list args)
{
	if (f_spec->precision_flag == '*')
		f_spec->precision = va_arg(args, int);
}

ssize_t	ft_output(t_format_specifier *f_spec, va_list args)
{
	ssize_t		err;
	
	ft_fetch_width(f_spec, args);
	ft_fetch_preci(f_spec, args);
	if (f_spec->specifier == 'i' || f_spec->specifier == 'd')
		err = ft_output_i_d(f_spec, args);
	if (f_spec->specifier == 'u')
		err = ft_output_i_d(f_spec, args);
	if (f_spec->specifier == 'x')
		err = ft_output_i_d(f_spec, args);
	return (err);
}

int	ft_process_str(char *str, va_list args)
{
	int	nb_char;
	int	error;
	t_format_specifier	*format_specifier;
	
	while (*str)
	{
		if (*str == '%')
		{
			format_specifier = (t_format_specifier *)malloc(sizeof(t_format_specifier));
			if (!format_specifier)
				return (-1);
			error = ft_init_format_specifier(format_specifier, str);
			if (error < 0)
				return (ft_error_format_specifier(format_specifier));
			
			
		}
		
		str++;
	}
}


int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_list	*list;
	t_list	*temp;
	size_t	size;

	list = NULL;
	va_start(args, s);
	list = ft_process_args(args, (char *)s);
	va_end(args);
	if (!list)
		return (-1);
	ft_lstiter(list, ft_print_node);
	temp = list;
	while (temp)
	{
		if (((t_node_contents *)temp->content)->write_error)
		{
			ft_lstclear(&list, ft_free_node_content);
			return (-1);
		}
		temp = temp->next;
	}
	size = ft_lstsum(list, ft_get_strlen);
	ft_lstclear(&list, ft_free_node_content);
	return (size);
}

// int	ft_printf(const char *s, ...)
// {
// 	va_list	args;
// 	t_list	*list;
// 	t_list	*temp;
// 	size_t	size;

// 	list = NULL;
// 	va_start(args, s);
// 	list = ft_process_args(args, (char *)s);
// 	va_end(args);
// 	if (!list)
// 		return (-1);
// 	ft_lstiter(list, ft_print_node);
// 	temp = list;
// 	while (temp)
// 	{
// 		if (((t_node_contents *)temp->content)->write_error)
// 		{
// 			ft_lstclear(&list, ft_free_node_content);
// 			return (-1);
// 		}
// 		temp = temp->next;
// 	}
// 	size = ft_lstsum(list, ft_get_strlen);
// 	ft_lstclear(&list, ft_free_node_content);
// 	return (size);
// }

// int	main(void)
// {
// 	//char *str = "string";
// 	//printf("%010d\n", 123456);
// 	//ft_printf("TEST\n");
// 	ft_printf("%c\n", 'A');
// 	// ft_printf("%s\n", str);
// 	// ft_printf("%p\n", str);
// 	// printf("%p\n", str);
// 	// ft_printf("%d\n", 123);
// 	// ft_printf("%i\n", -123);
// 	// ft_printf("%u\n", 1234);
// 	// ft_printf("%x\n", 123);
// 	// ft_printf("%X\n", 123);
// 	// ft_printf("%%\n");
// 	// ft_printf("hello world %d, i like %s", 42, "cheese");
// }

// %10d
// %-10d
// %010d
// %10.2d


// %[flags][width][.precision][length]specifier
