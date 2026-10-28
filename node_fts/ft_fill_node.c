/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:03:25 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:03:46 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_fts.h"

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