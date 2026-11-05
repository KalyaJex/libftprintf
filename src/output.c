/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:19:47 by svannay           #+#    #+#             */
/*   Updated: 2026/11/05 15:25:21 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// ssize_t	ft_puthexnbr_fd(int n, int fd, t_lettercase lettercase)
// {
// 	long int	ln;

// 	ln = (long int)n;
// 	if (ln < 0)
// 	{
// 		if (ft_putchar_fd('-', fd) < 0)
// 			return (-1);
// 		ln *= -1;
// 	}
// 	if (ln < 16)
// 	{
// 		if (ft_putchar_fd(ft_getbase(lettercase)[ln % 16], fd) < 0)
// 			return (-1);
// 	}
// 	if (ln >= 16)
// 	{
// 		if (ft_puthexnbr_fd(ln / 16, fd, lettercase) < 0)
// 			return (-1);
// 		if (ft_putchar_fd(ft_getbase(lettercase)[ln % 16], fd) < 0)
// 			return (-1);
// 	}
// }

// ssize_t	ft_putubase_fd(unsigned long int n,
// 		int fd,
// 		t_lettercase lettercase,
// 		unsigned int base_size)
// {
// 	if (n < base_size)
// 	{
// 		if (ft_putchar_fd(ft_getbase(lettercase)[n % base_size], fd) < 0)
// 			return (-1);
// 	}
// 	if (n >= base_size)
// 	{
// 		if (ft_putubase_fd(n / base_size, fd, lettercase, base_size) < 0)
// 			return (-1);
// 		if (ft_putchar_fd(ft_getbase(lettercase)[n % base_size], fd) < 0)
// 			return (-1);
// 	}
// }

// ssize_t	ft_putaddress_fd(void *ptr)
// {
// 	uintptr_t p;

// 	p = (uintptr_t)ptr;
// 	if (ft_putstr_fd("0x", 1) < 0)
// 		return (-1);
// 	if (ft_putubase_fd(p, 1, LOWERCASE, 16) < 0)
// 		return (-1);
// }
