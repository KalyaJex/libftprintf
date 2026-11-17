/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:06:14 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:13:19 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_check_zero_precision(t_format_specifier *f_spec, unsigned int n)
{
	if (n == 0)
	{
		if (f_spec->precision_flag == '0'
			|| (f_spec->precision_flag == '.' && f_spec->precision == 0))
			return (1);
	}
	return (0);
}

t_char_count	*ft_output_u(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count)
{
	unsigned int	n;

	if (char_count->error == -1)
		return (char_count);
	n = (unsigned int)va_arg(args, unsigned int);
	if (!ft_check_zero_precision(f_spec, n))
		ft_putunbr(n, BASE10, LOWERCASE, char_count);
	return (char_count);
}
