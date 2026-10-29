/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:03:40 by svannay           #+#    #+#             */
/*   Updated: 2026/10/19 09:11:30 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*p;
	unsigned char	cc;

	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	cc = (unsigned char)c;
	p = (char *)s;
	while (*p)
	{
		if (*p == cc)
			return (p);
		p++;
	}
	return (NULL);
}
