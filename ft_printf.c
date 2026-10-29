/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:29 by svannay           #+#    #+#             */
/*   Updated: 2026/10/29 11:53:19 by svannay          ###   ########.fr       */
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
	ft_putstr_fd(((t_node_contents *)content)->substr, 1);
	
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

int	ft_printf(const char *s, ...)
{
	va_list			args;
	t_list			*list;
	t_list			*temp;

	va_start(args, s);
	ft_putstr_fd("CHECK START\n", 1);
	list = ft_process_args(args, (char *)s);
	va_end(args);
	// TODO: display
	if (!list)
		return (-1);
	temp = list;
	// while (temp)
	// {
	// 	ft_putstr_fd(((t_node_contents *)temp->content)->substr, 1);
	// 	//ft_splitter(args, ((t_node_contents *)temp->content)->symbol);
	// 	temp = temp->next;
	// }
	ft_lstiter(list, ft_print_node);
	ft_putstr_fd("CHECK END\n", 1);
	ft_lstclear(&list, ft_free_node_content);
	return (0);
}

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
