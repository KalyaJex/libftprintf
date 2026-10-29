/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:37:16 by svannay           #+#    #+#             */
/*   Updated: 2026/10/12 09:06:23 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start(char const *s1, char const *set, size_t set_size)
{
	char	*pset;
	int		start;
	size_t	set_size_copy;

	start = 0;
	while (1)
	{
		set_size_copy = set_size;
		pset = (char *)set;
		while (0 < set_size_copy)
		{
			if (*s1 == *pset)
			{
				s1++;
				start++;
				break ;
			}
			pset++;
			set_size_copy--;
		}
		if (!*pset)
			break ;
	}
	return (start);
}

static int	ft_get_end(char const *s1,
							char const *set,
							size_t src_size,
							size_t set_size)
{
	char	*pset;
	int		end;
	size_t	set_size_copy;

	end = 0;
	while (0 < src_size)
	{
		set_size_copy = set_size;
		pset = (char *)set;
		while (0 < set_size_copy)
		{
			if (*(s1 + src_size - 1) == *pset)
			{
				end++;
				break ;
			}
			pset++;
			set_size_copy--;
		}
		if (!*pset)
			break ;
		src_size--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	src_size;
	size_t	set_size;
	int		start;
	int		end;

	set_size = ft_strlen((char *) set);
	src_size = ft_strlen((char *)s1);
	start = ft_get_start(s1, set, set_size);
	end = ft_get_end(s1, set, ft_strlen((char *) s1), set_size);
	return (ft_substr(s1, start, src_size - start - end));
}
