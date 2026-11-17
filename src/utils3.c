/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:02:45 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:09:20 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_fetch_width_preci(t_format_specifier *f_spec, va_list args)
{
	if (f_spec->width_flag == '*')
		f_spec->width = va_arg(args, int);
	if (f_spec->precision_flag == '*')
		f_spec->precision = va_arg(args, int);
}

int	ft_count_digit_space(long long int n, unsigned int base,
		t_format_specifier *f_spec)
{
	if (n >= 0 && ft_strcontain(f_spec->flag, ' '))
		return (ft_count_digits(n, base) + 1);
	return (ft_count_digits(n, base));
}

void	ft_init_char_count(t_char_count **char_count)
{
	(*char_count)->error = 0;
	(*char_count)->nb = 0;
}
