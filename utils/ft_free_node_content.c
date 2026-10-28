/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:31:07 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:32:07 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_node_content(void *content)
{
	if (((t_node_contents *)content)->format_specifier)
		ft_free_format_specifier(((t_node_contents *)content)->format_specifier);
	free(((t_node_contents *)content)->substr);
	if (content)
		free(content);
}