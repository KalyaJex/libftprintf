/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:37:50 by svannay           #+#    #+#             */
/*   Updated: 2026/10/19 10:23:43 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*pdest;
	char	*psrc;
	size_t	src_size;

	src_size = ft_strlen((char *)src);
	pdest = dest;
	psrc = (char *)src;
	if (size == 0)
		return (src_size);
	while (0 < size - 1 && *psrc)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
		size--;
	}
	*pdest = '\0';
	return (src_size);
}
