/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:12:09 by svannay           #+#    #+#             */
/*   Updated: 2026/10/29 11:26:48 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		node_content->format_specifier = NULL;
	else
	{
		format_specifier_l = ft_init_node(node_content, next, args);
		
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
		node->print_value.p = va_arg(args, void *);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		node->print_value.i = va_arg(args, int);
	return (0);
}

int	ft_init_node(t_node_contents *node, char *str, va_list args)
{
	t_format_specifier	*format_specifier;
	int			format_specifier_l;

	format_specifier_l = 0;
	format_specifier = (t_format_specifier *)malloc(sizeof(t_format_specifier));
	if (!format_specifier)
		return (-1);
	format_specifier_l = ft_init_format_specifier(format_specifier, str);
	if (0 > format_specifier_l)
		return (ft_error_format_specifier(format_specifier));
	node->format_specifier = format_specifier;
	node->substr = str;
	if (0 > ft_get_arg(node, args))
		return (ft_error_init_node(node));
	if (node->format_specifier->width_flag)
		node->format_specifier->width = va_arg(args, int);
	if (node->format_specifier->precision_flag)
		node->format_specifier->precision = va_arg(args, int);
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
			ft_fill_node(&list,
							"",
							ft_substr(s, length, ft_strlen((char *)s)),
							args);
			break ;
		}
		length = ft_fill_node(&list, next + 1, ft_substr(s, length, next - s), args);
		if (0 > length)
			return (NULL);
		s = next + length + 1;
	}
	return (list);
	
}