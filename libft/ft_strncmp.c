/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:18:45 by svannay           #+#    #+#             */
/*   Updated: 2026/10/19 14:15:27 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	while (0 < n && *p1 && (*p1 == *p2))
	{
		p1++;
		p2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)p1 - *(unsigned char *)p2);
}
