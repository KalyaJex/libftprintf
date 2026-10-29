/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:49:03 by svannay           #+#    #+#             */
/*   Updated: 2026/10/19 15:01:06 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*temp;

	if (start > ft_strlen((char *)s))
		start = ft_strlen((char *)s);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	while (start--)
		s++;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	temp = ptr;
	while (0 < len && *s)
	{
		*temp = *s;
		temp++;
		s++;
		len--;
	}
	*temp = '\0';
	return (ptr);
}
