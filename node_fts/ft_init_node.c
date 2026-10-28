/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:02:20 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:02:31 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_fts.h"

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