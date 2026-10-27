/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:19:47 by svannay           #+#    #+#             */
/*   Updated: 2026/10/27 11:14:09 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_getbase(t_lettercase lettercase)
{
	char	*upper_base;
	char	*lower_base;

	upper_base = "0123456789ABCDEF";
	lower_base = "0123456789abcdef";
	if (lettercase == UPPERCASE)
		return (upper_base);
	else
		return (lower_base);
}

void	ft_puthexnbr_fd(int n, int fd, t_lettercase lettercase)
{
	long int	ln;

	ln = (long int)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln < 16)
	{
		ft_putchar_fd(ft_getbase(lettercase)[ln % 16], fd);
	}
	if (ln >= 16)
	{
		ft_puthexnbr_fd(ln / 16, fd, lettercase);
		ft_putchar_fd(ft_getbase(lettercase)[ln % 16], fd);
	}
}

void	ft_putubase_fd(unsigned long int n, int fd, t_lettercase lettercase, unsigned int base_size)
{
	if (n < base_size)
	{
		ft_putchar_fd(ft_getbase(lettercase)[n % base_size], fd);
	}
	if (n >= base_size)
	{
		ft_putubase_fd(n / base_size, fd, lettercase, base_size);
		ft_putchar_fd(ft_getbase(lettercase)[n % base_size], fd);
	}
}

void	ft_putaddress_fd(void *ptr)
{
	uintptr_t p;

	p = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	ft_putubase_fd(p, 1, LOWERCASE, 16);
}
