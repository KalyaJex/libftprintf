/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:31:12 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 11:14:30 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_char_count	*ft_putstr_fd(char *s, int fd, t_char_count *char_count)
{
	if (!s || char_count->error == -1)
		return (char_count->error = -1, char_count);
	while (*s)
	{
		if (ft_putchar_fd(*s, fd, char_count)->error == -1)
			return (char_count);
		s++;
	}
	return (char_count);
}
