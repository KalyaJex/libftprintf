/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:56:07 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 11:09:09 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_char_count	*ft_putchar_fd(char c, int fd, t_char_count *char_count)
{
	ssize_t	temp;

	if (char_count->error == -1)
		return (char_count);
	temp = write(fd, &c, 1);
	if (temp == -1)
		return (char_count->error = -1, char_count);
	if (!char_count->nb)
		return (char_count->nb = temp, char_count);
	return (char_count->nb += temp, char_count);
}
