/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:06 by svannay           #+#    #+#             */
/*   Updated: 2026/11/02 16:49:11 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strcontain(char *str, int c)
{
	if (!str)
		return (0);
	if (!ft_strchr(str, c))
		return (0);
	return (1);
}

char	*ft_extract_substr(char *str, int (*check)(int))
{
	unsigned int	index;

	index = 0;
	while(str[index])
	{
		if (check(str[index]))
			break ;
		index++;
	}
	return (ft_substr(str, 0, index + 1));
}

char	*ft_strinsert(char *dest, char *src, unsigned int pos)
{
	char	*sub;
	char	*start;
	char	*new;
	char	*inter;
	size_t	total_len;
	
	if (pos > ft_strlen(dest))
		return (NULL);
	if (pos == 0)
		return (ft_strjoin(src, dest));
	sub = ft_substr(dest, pos, ft_strlen(dest) - pos);
	start = ft_substr(dest, 0, pos);
	if (!sub || !start)
		return (NULL);
	total_len = ft_strlen(dest) + ft_strlen(src);
	if (!new)
		return (NULL);
	inter = ft_strjoin(start, src);
	new = ft_strjoin(inter, sub);
	free(sub);
	free(start);
	free(inter);
	return (new);
}