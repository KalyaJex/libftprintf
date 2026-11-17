/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:37:26 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 11:36:28 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_char_count	*ft_putnbr_fd(int n, int fd, t_char_count *char_count)
{
	long int	l_n;

	if (char_count->error == -1)
		return (char_count);
	l_n = n;
	if (l_n < 0)
	{
		if (ft_putchar_fd('-', fd, char_count)->error == -1)
			return (char_count);
		l_n *= -1;
	}
	if (l_n < 10)
	{
		if (ft_putchar_fd(l_n + '0', fd, char_count)->error == -1)
			return (char_count);
	}
	if (l_n >= 10)
	{
		if (ft_putnbr_fd(l_n / 10, fd, char_count)->error == -1)
			return (char_count);
		if (ft_putchar_fd((l_n % 10) + '0', fd, char_count)->error == -1)
			return (char_count);
	}
	return (char_count);
}
