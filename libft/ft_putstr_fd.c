/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:31:12 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 11:05:15 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	unsigned int	nb_char;

	nb_char = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (ft_putchar_fd(*s, fd) < 0)
			return (-1);
		s++;
		nb_char++;
	}
	return (nb_char);
}
