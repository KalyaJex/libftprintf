/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:06 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:11:30 by svannay          ###   ########.fr       */
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

	if (*(str) == '%')
		return (ft_substr(str, 0, 1));
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
		if (!check(str[index + 1]))
			break ;
		if (index
			&& !(check(str[index]) && check(str[index - 1])))
			break ;
		index++;
	}
	return (ft_substr(str, 0, index + 1));
}
