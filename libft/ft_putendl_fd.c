/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:35:08 by svannay           #+#    #+#             */
/*   Updated: 2026/11/05 15:26:34 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	if (ft_putstr_fd(s, fd) < 0)
		return (-1);
	if (ft_putchar_fd('\n', fd) < 0)
		return (-1);
	return (0);
}
