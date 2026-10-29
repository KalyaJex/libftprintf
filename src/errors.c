/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:15:07 by svannay           #+#    #+#             */
/*   Updated: 2026/10/29 11:27:01 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_error_fill_node(t_list **list)
{
	if (*list)
		ft_lstclear(list, ft_free_node_content);
	return (-1);
}

int	ft_error_format_specifier(t_format_specifier *format_specifier)
{
	ft_free_format_specifier(format_specifier);
	return (-1);
}

int	ft_error_init_node(t_node_contents *node)
{
	ft_free_node_content(node);
	return (-1);
}