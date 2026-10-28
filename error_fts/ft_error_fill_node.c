/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_fill_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:34:35 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:36:53 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_fts.h"

int	ft_error_fill_node(t_list **list)
{
	if (*list)
		ft_lstclear(list, ft_free_node_content);
	return (-1);
}
