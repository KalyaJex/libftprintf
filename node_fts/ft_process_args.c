/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:05:10 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:05:28 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_fts.h"

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