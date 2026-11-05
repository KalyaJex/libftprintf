/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:37:26 by svannay           #+#    #+#             */
/*   Updated: 2026/11/05 15:26:23 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	long int	l_n;

	l_n = n;
	if (l_n < 0)
	{
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		l_n *= -1;
	}
	if (l_n < 10)
	{
		if (ft_putchar_fd(l_n + '0', fd) < 0)
			return (-1);
	}
	if (l_n >= 10)
	{
		if (ft_putnbr_fd(l_n / 10, fd) < 0)
			return (-1);
		if (ft_putchar_fd((l_n % 10) + '0', fd) < 0)
			return (-1);
	}
	return (0);
}
