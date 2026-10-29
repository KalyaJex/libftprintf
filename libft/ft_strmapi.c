/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:45:27 by svannay           #+#    #+#             */
/*   Updated: 2026/10/12 14:22:58 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_innit_str(char *s)
{
	char	*new_str;
	int		s_len;

	s_len = ft_strlen(s);
	new_str = malloc((s_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	*(new_str + s_len) = '\0';
	return (new_str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		index;

	index = 0;
	new_str = ft_innit_str((char *)s);
	if (!new_str)
		return (NULL);
	while (*s)
	{
		new_str[index] = f(index, *s);
		index++;
		s++;
	}
	return (new_str);
}
