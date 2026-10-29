/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 13:41:57 by svannay           #+#    #+#             */
/*   Updated: 2026/10/09 10:37:09 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	int				is_backward;

	pdest = dest;
	psrc = src;
	if (pdest == psrc || n == 0)
		return (dest);
	if ((dest - src) > 0)
		is_backward = 1;
	else
		is_backward = 0;
	while (0 < n)
	{
		if (is_backward)
			*(pdest + n - 1) = *(psrc + n - 1);
		else
		{
			*pdest = *psrc;
			pdest++;
			psrc++;
		}
		n--;
	}
	return (dest);
}
