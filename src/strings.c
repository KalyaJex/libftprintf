/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:06 by svannay           #+#    #+#             */
/*   Updated: 2026/11/05 14:41:49 by svannay          ###   ########.fr       */
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

char	*ft_extract_format(char *str, int (*check)(int))
{
	unsigned int	index;

	//printf("C %c\n", *str);
	if (*(str) == '%')
		return(ft_substr(str, 0, 1));
	index = 0;
	while (str[index])
	{
		if (check(str[index]))
			break ;
		index++;
	}
	return (ft_substr(str, 0, index + 1));
}

char	*ft_extract_subspecifier(char *str, int (*check)(int))
{
	unsigned int	index;

	index = 0;
	while (str[index])
	{
		if (index
			&& (check(str[index]) && check(str[index - 1])))
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

	if (pos > ft_strlen(dest))
		return (NULL);
	if (pos == 0)
		return (ft_strjoin(src, dest));
	sub = ft_substr(dest, pos, ft_strlen(dest) - pos);
	if (!sub)
		return (ft_free_all(1, src));
	start = ft_substr(dest, 0, pos);
	if (!start)
		return (ft_free_all(2, sub, src));
	inter = ft_strjoin(start, src);
	if (!inter)
		return (ft_free_all(3, sub, start, src));
	new = ft_strjoin(inter, sub);
	if (!new)
		return (ft_free_all(4, sub, start, inter, src));
	ft_free_all(4, sub, start, inter, src);
	return (new);
}

char	*strndup(const char *s, size_t n)
{
	char	*ptr;
	char	*temp;
	size_t		size;

	size = ft_strlen((char *)s);
	if (size < n)
		n = size;
	ptr = malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	temp = ptr;
	while (0 < n)
	{
		*temp = *s;
		temp++;
		s++;
		n--;
	}
	*temp = '\0';
	return (ptr);
}
