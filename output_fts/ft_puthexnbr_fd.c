/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:13:41 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:15:29 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_fts.h"

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