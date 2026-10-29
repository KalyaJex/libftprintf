/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:12:37 by svannay           #+#    #+#             */
/*   Updated: 2026/10/19 14:15:37 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*p;
	int				size;
	unsigned char	cc;

	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	p = (char *)s;
	size = ft_strlen(p);
	cc = (unsigned char)c;
	while (0 < size)
	{
		if (*(p + size - 1) == cc)
			return (p + size - 1);
		size--;
	}
	return (NULL);
}
