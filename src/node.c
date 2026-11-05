/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:12:09 by svannay           #+#    #+#             */
/*   Updated: 2026/11/05 17:10:39 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_create_address(uintptr_t ptr)
{
	char	*str;
	char	*start;
	size_t	size;

	if (ptr == 0)
		return (ft_strdup("(nil)"));
	str = ft_ultoa(ptr, BASE16, LOWERCASE);
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	start = malloc((size + 3) * sizeof(char));
	if (!start)
		return (NULL);
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
		return (ft_ltoa(node->print_value.i, BASE16, LOWERCASE));
	else if (c == 'X')
		return (ft_ltoa(node->print_value.i, BASE16, UPPERCASE));
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
	padding = ft_create_padding(format_specifier->width - len,
			ft_get_padding_char(format_specifier));
	if (!padding)
		return (str);
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
	char				*new;
	t_format_specifier	*format_spec;

	format_spec = node->format_specifier;
	new = NULL;
	if (ft_strcontain("diuxX", format_spec->specifier)
		&& format_spec->precision > len)
	{
		if (node->print_value.i > 0)
			new = ft_strinsert(str,
					ft_create_padding(format_spec->precision - len, '0'),
					0);
		else
			new = ft_strinsert(str,
					ft_create_padding(format_spec->precision - len + 1, '0'),
					1);
	}
	else if (format_spec->specifier == 's'
		&& format_spec->precision_flag)
		new = strndup(str, format_spec->precision);
	if (!new)
		return (str);
	free(str);
	return (new);
}

char	*ft_create_str(t_node_contents *node)
{
	char	*str;
	
	//printf("%d\n", node->format_specifier->is_gibberish);
	if (node->format_specifier->is_gibberish)
		return (ft_strinsert(node->format_specifier->og_ptr, "%", 0));
	str = ft_splitter(node);
	if (!str)
		return (NULL);
	str = ft_apply_precision(node, str, ft_strlen(str));
	if (node->format_specifier->width > ft_strlen(str))
		str = ft_apply_width(node, str, ft_strlen(str));
	//printf("%s\n", str);
	return (str);
}

int	ft_fill_content(t_node_contents *content, char *next, char *substr, va_list args)
{
	int	format_specifier_l;

	format_specifier_l = 0;
	if (!*next)
	{
		content->format_specifier = NULL;
		content->str_to_print = NULL;
		content->write_error = FALSE;
	}
	else
	{
		format_specifier_l = ft_init_node(content, next, args);
		if (0 > format_specifier_l)
			return (-1);
		if (content->format_specifier && content->format_specifier->specifier == 'c')
			content->str_to_print = NULL;
		else
			content->str_to_print = ft_create_str(content);
	} 
	content->substr = substr;
	return (format_specifier_l);
}

int	ft_fill_node(t_list **list, char *next, char *substr, va_list args)
{
	t_node_contents	*node_content;
	t_list			*node;
	int				format_specifier_l;

	if (!substr)
		return (ft_error_fill_node(list));
	node = NULL;
	format_specifier_l = 0;
	node_content = (t_node_contents *)malloc(sizeof(t_node_contents));
	if (!node_content)
		return (ft_error_fill_node(list));
	format_specifier_l = ft_fill_content(node_content, next, substr, args);
	if (0 > format_specifier_l)
		return (ft_error_fill_node(list));
	node = ft_lstnew(node_content);
	if (!node)
		return (ft_error_fill_node(list));
	ft_lstadd_back(list, node);
	return (format_specifier_l);
}

int ft_get_arg(t_node_contents *node, va_list args)
{
	char	c;

	c = node->format_specifier->specifier;
	if (c == '%')
	{
		node->print_value.c = '%';
		return (0);
	}
	if (c == 'c')
		node->print_value.c = (unsigned char)va_arg(args, int);
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
		node->print_value.i = (long int)va_arg(args, long int);
	return (0);
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
	node->write_error = 0;
	if (node->format_specifier->is_gibberish)
		return (format_specifier_l);
	if (node->format_specifier->width_flag == '*')
		node->format_specifier->width = va_arg(args, int);
	if (node->format_specifier->precision_flag == '*')
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