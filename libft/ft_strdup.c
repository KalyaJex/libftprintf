/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 10:52:04 by svannay           #+#    #+#             */
/*   Updated: 2026/10/07 15:38:43 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*temp;
	int		size;

	size = ft_strlen((char *)s);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	temp = ptr;
	while (0 < size)
	{
		*temp = *s;
		temp++;
		s++;
		size--;
	}
	*temp = '\0';
	return (ptr);
}
