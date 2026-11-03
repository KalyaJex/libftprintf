/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:02:33 by svannay           #+#    #+#             */
/*   Updated: 2026/11/03 11:13:26 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isflag(int c)
{
	if (!ft_strchr("-+ #0", c))
		return (0);
	return (1);
}

int	ft_islength(int c)
{
	if (!ft_strchr("hljztL", c))
		return (0);
	return (1);
}

int	ft_isprecision(int c)
{
	return (c == '.');
}

int	ft_isspecifier(int c)
{
	if (!c || !ft_strchr("cspdiuxX%", c))
		return (0);
	return (1);
}

int ft_check_next_spec(int c)
{
	if (ft_isspecifier(c) || c == '%' || c == '\0')
		return (1);
}
