/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:27:38 by svannay           #+#    #+#             */
/*   Updated: 2026/10/16 16:53:25 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	cc;

	cc = (unsigned char)c;
	p = (unsigned char *)s;
	while (0 < n)
	{
		if (*p == cc)
			return (p);
		n--;
		p++;
	}
	return (NULL);
}
