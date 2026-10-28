/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:15:14 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:16:20 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_fts.h"

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