/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 15:19:04 by svannay           #+#    #+#             */
/*   Updated: 2026/11/05 13:47:07 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_get_strlen(void *content)
{
	size_t				substr_len;
	size_t				str_len;
	t_format_specifier	*format_specifier;
	
	str_len = 0;
	substr_len = 0;
	format_specifier = ((t_node_contents *)content)->format_specifier;
	//printf("TEST\n");
	//printf("spec %p\n", ((t_node_contents *)content)->format_specifier);
	if (format_specifier && format_specifier->specifier == 'c')
		str_len = 1;
	else if (((t_node_contents *)content)->str_to_print)
		str_len = ft_strlen(((t_node_contents *)content)->str_to_print);
	if (((t_node_contents *)content)->substr)
		substr_len = ft_strlen(((t_node_contents *)content)->substr);
	return (str_len + substr_len);
}

size_t	ft_lstsum(t_list *list, size_t (*getlen)(void *))
{
	size_t	sum;

	sum = 0;
	while (list)
	{
		sum += getlen(list->content);	
		list = list->next;
	}
	return (sum);
}