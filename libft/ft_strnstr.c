/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 08:38:33 by svannay           #+#    #+#             */
/*   Updated: 2026/10/19 14:28:26 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pbig;
	char	*temp;
	char	*plittle;
	size_t	n;

	if (!*little)
		return ((char *)big);
	pbig = (char *)big;
	while (*pbig && 0 < len)
	{
		temp = pbig;
		plittle = (char *)little;
		n = len;
		while (*plittle && *temp == *plittle && 0 < n)
		{
			temp++;
			plittle++;
			n--;
		}
		if (!*plittle)
			return (pbig);
		pbig++;
		len--;
	}
	return (NULL);
}
