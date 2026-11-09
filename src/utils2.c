/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:01:23 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 15:15:41 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_count_udigits(unsigned long long int n, unsigned int base)
{
	int			count;
	int			is_negative;

	is_negative = 0;
	if (n == 0)
		return (1);
	count = 0;
	while (0 < n)
	{
		n /= base;
		count++;
	}
	return (count + is_negative);
}

unsigned int ft_pow(unsigned int n, unsigned int pow)
{
	uintptr_t total;
	
	total = 1;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (n);
	while (pow > 0)
	{
		total *= n;
		pow--;
	}
	return (total);
}

uintptr_t ft_pow_ptr(uintptr_t n, unsigned int pow)
{
	uintptr_t total;
	
	total = 1;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (n);
	while (pow > 0)
	{
		total *= n;
		pow--;
	}
	return (total);
}

int	ft_isneg(long int n)
{
	return (n < 0);
}

unsigned int	ft_get_preci_l(t_format_specifier *f_spec)
{
	if (!f_spec->precision_flag || f_spec->precision_flag == '0')
		return (0);
	return (f_spec->precision);
}

void	ft_fetch_width_preci(t_format_specifier *f_spec, va_list args)
{
	if (f_spec->width_flag == '*')
		f_spec->width = va_arg(args, int);
	if (f_spec->precision_flag == '*')
		f_spec->precision = va_arg(args, int);
}