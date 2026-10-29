/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:01:47 by svannay           #+#    #+#             */
/*   Updated: 2026/10/20 13:42:44 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_free_all(char **tab)
{
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tab);
	return (NULL);
}

static char	*ft_get_next_sep(char *s, char c)
{
	char	*next;

	next = ft_strchr(s, c);
	if (!next)
		return (s + ft_strlen(s));
	return (next);
}

static int	ft_countwords(char *s, char c)
{
	int		index;
	char	*pend;

	index = 0;
	pend = s;
	if (!s || !*s)
		return (0);
	if (c == 0)
		return (1);
	while (*pend)
	{
		pend = ft_get_next_sep(s, c);
		if (pend - s > 0)
			index++;
		s = pend + 1;
	}
	return (index);
}

static char	**ft_fill(char *s, char c, char **arr, int nb_words)
{
	char	*pend;
	int		index;

	index = 0;
	pend = s;
	while (*pend && index < nb_words)
	{
		pend = ft_get_next_sep(s, c);
		if (pend - s > 0)
		{
			arr[index] = ft_substr(s, 0, pend - s);
			if (!arr[index])
				return (ft_free_all(arr));
			index++;
		}
		s = pend + 1;
	}
	arr[index] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	char	**arr;

	nb_words = ft_countwords((char *)s, c);
	arr = malloc((nb_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!s || nb_words == 0)
		arr[0] = NULL;
	else if (c == 0)
	{
		arr[0] = ft_strdup(s);
		arr[1] = NULL;
	}
	else
		arr = ft_fill((char *)s, c, arr, nb_words);
	return (arr);
}
