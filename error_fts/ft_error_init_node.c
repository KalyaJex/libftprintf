/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_init_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:56:38 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:56:48 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_fts.h"

int	ft_error_init_node(t_node_contents *node)
{
	ft_free_node_content(node);
	return (-1);
}
