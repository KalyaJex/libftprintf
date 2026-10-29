/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:37:26 by svannay           #+#    #+#             */
/*   Updated: 2026/10/12 14:25:52 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l_n;

	l_n = n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n *= -1;
	}
	if (l_n < 10)
	{
		ft_putchar_fd(l_n + '0', fd);
	}
	if (l_n >= 10)
	{
		ft_putnbr_fd(l_n / 10, fd);
		ft_putchar_fd((l_n % 10) + '0', fd);
	}
}
