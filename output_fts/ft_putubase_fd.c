/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putubase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:20:37 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:26:48 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_fts.h"

void	ft_putubase_fd(unsigned long int n,
			int fd,
			t_lettercase lettercase,
			unsigned int base_size)
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