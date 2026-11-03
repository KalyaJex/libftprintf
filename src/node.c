/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:12:09 by svannay           #+#    #+#             */
/*   Updated: 2026/11/03 09:30:23 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_create_address(intptr_t ptr)
{
	char	*str;
	char	*start;
	size_t	size;

	str = ft_ltoa(ptr, BASE16, LOWERCASE);
	if (!str)
		return NULL;
	size = ft_strlen(str);
	start = malloc((size + 3) * sizeof(char));
	if (!start)
		return NULL;
	start[0] = '0';
	start[1] = 'x';
	start[2] = '\0';
	ft_strlcat(start, str, size + 3);
	free(str);
	return (start);
}

char	*ft_splitter(t_node_contents *node)
{
	char		c;
	//printf("%c", node->format_specifier->specifier);
	c = node->format_specifier->specifier;
	if (c == '%')
		return (ft_ctos(node->print_value.c));
	else if (c == 'c')
		return (ft_ctos(node->print_value.c));
	else if (c == 's')
		return (ft_strdup(node->print_value.s));
	else if (c == 'p')
		return (ft_create_address(node->print_value.p));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(node->print_value.i, BASE10, LOWERCASE));
	else if (c == 'u')
		return (ft_utoa(node->print_value.u, BASE10, LOWERCASE));
	else if (c == 'x')
		return (ft_itoa(node->print_value.i, BASE16, LOWERCASE));
	else if (c == 'X')
		return (ft_itoa(node->print_value.i, BASE16, UPPERCASE));
	return (NULL);
}

char	ft_get_padding_char(t_format_specifier *format_specifier)
{
	if (ft_strcontain(format_specifier->flag, '0')
		&& !ft_strcontain(format_specifier->flag, '-')
		&& format_specifier->precision <= 0)
		return ('0');
	else
		return (' ');
}

char	*ft_create_padding(unsigned int size, char c)
{
	char				*padding;
	unsigned int		index;
	
	index = 0;
	padding = malloc((size + 1) * sizeof(char));
	if (!padding)
		return (NULL);
	while (index < size)
	{
		padding[index] = c;
		index++;
	}
	padding[index] = '\0';
	return (padding);
}

char	*ft_apply_width(t_node_contents *node, char *str, size_t len)
{
	char				*padding;
	char				*new;
	unsigned int		index;
	t_format_specifier	*format_specifier;
	
	index = 0;
	format_specifier = node->format_specifier;
	padding = ft_create_padding(format_specifier->width - len, ft_get_padding_char(format_specifier));
	if (ft_strcontain(format_specifier->flag, '-'))
		new = ft_strjoin(str, padding);
	else
		new = ft_strjoin(padding, str);
	free(padding);
	free(str);
	return (new);
}

char	*ft_apply_precision(t_node_contents *node, char *str, size_t len)
{
	char				*padding;
	char				*new;
	unsigned int		index;
	t_format_specifier	*format_specifier;
	
	format_specifier = node->format_specifier;
	if (ft_strcontain("diuxX", format_specifier->specifier))
	{
		if (node->print_value.i > 0)
			new = ft_strinsert(str, ft_create_padding(format_specifier->precision - len, '0'), 0);
		else
			new = ft_strinsert(str, ft_create_padding(format_specifier->precision - len, '0'), 1);
		return (new);
	}
	else if (format_specifier->specifier == 's')
	{
		
	}
}

char	*ft_create_str(t_node_contents *node)
{
	char	*str;
	size_t	len;
	char	*padding;
	

	padding = NULL;
	str = ft_splitter(node);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (node->format_specifier->precision > len)
	{
		
	}
	if (node->format_specifier->width > len)
		return (ft_apply_width(node, str, len));
	return (str);
}

int	ft_fill_node(t_list **list, char *next, char *substr, va_list args)
{
	t_node_contents	*node_content;
	t_list			*node;
	int				format_specifier_l;

	node = NULL;
	format_specifier_l = 0;
	node_content = (t_node_contents *)malloc(sizeof(t_node_contents));
	if (!node_content)
		return (ft_error_fill_node(list));
	if (!*next)
	{
		node_content->format_specifier = NULL;
		node_content->str_to_print = NULL;
	}
	else
	{
		format_specifier_l = ft_init_node(node_content, next, args);
		node_content->str_to_print = ft_create_str(node_content);
	} 
	if (0 > format_specifier_l)
		return (ft_error_fill_node(list));
	node_content->substr = substr;
	node = ft_lstnew(node_content);
	if (!node)
		return (ft_error_fill_node(list));
	ft_lstadd_back(list, node);
	return (format_specifier_l);
}

int ft_get_arg(t_node_contents *node, va_list args)
{
	char	c;
	//uintptr_t	p;

	c = node->format_specifier->specifier;
	if (c == '%')
	{
		node->print_value.c = '%';
		return (0);
	}
	if (c == 'c')
		node->print_value.c = (char)va_arg(args, int);
	else if (c == 's')
	{
		node->print_value.s = ft_strdup(va_arg(args, char *));
		if (!node->print_value.s)
			return (-1);
	}
	else if (c == 'p')
	{
		node->print_value.p = (uintptr_t)va_arg(args, void *);
	}
	else if (c == 'u')
		node->print_value.u = va_arg(args, unsigned int);
	else if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		node->print_value.i = va_arg(args, int);
	return (0);
}

char	*ft_char_to_str(char c)
{
	char		*str;
	
	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0'; 
	return (str);
}

int	ft_init_node(t_node_contents *node, char *next, va_list args)
{
	t_format_specifier	*format_specifier;
	int					format_specifier_l;

	format_specifier_l = 0;
	format_specifier = (t_format_specifier *)malloc(sizeof(t_format_specifier));
	if (!format_specifier)
		return (-1);
	format_specifier_l = ft_init_format_specifier(format_specifier, next);
	if (0 > format_specifier_l)
		return (ft_error_format_specifier(format_specifier));
	node->format_specifier = format_specifier;
	if (node->format_specifier->width_flag)
		node->format_specifier->width = va_arg(args, int);
	if (node->format_specifier->precision_flag)
		node->format_specifier->precision = va_arg(args, int);
	if (0 > ft_get_arg(node, args))
		return (ft_error_init_node(node));
	return (format_specifier_l);
}

t_list	*ft_process_args(va_list args, char *s)
{
	t_list	*list;
	char	*next;
	int		length;

	list = NULL;
	length = 0;
	while (1)
	{
		next = ft_strchr(s, '%');
		if (!next)
		{
			//printf("%s", s);
			ft_fill_node(&list,
							"",
							ft_substr(s, 0, ft_strlen((char *)s)),
							args);
			break ;
		}
		length = ft_fill_node(&list, next + 1, ft_substr(s, 0, next - s), args);
		if (0 > length)
			return (NULL);
		s = next + length + 1;
	}
	return (list);
	
}