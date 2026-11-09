/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:13:45 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 16:17:46 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_left_padding_c(t_format_specifier *f_spec)
{
	ssize_t	err;

	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	err = ft_write_pad(f_spec->width - 1, ' ');
	return (err);
}

ssize_t	ft_left_padding_s(t_format_specifier *f_spec, char *s)
{
	size_t	slen;
	ssize_t	err;

	err = 0;
	slen = ft_strlen(s);
	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	if (f_spec->precision_flag == '0')
		err = ft_write_pad(f_spec->width, ' ');
	else if (!f_spec->precision_flag && slen < f_spec->width)
		err = ft_write_pad(f_spec->width - slen, ' ');
	else if (ft_get_preci_l(f_spec) < slen)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec), ' ');
	return (err);
}

ssize_t	ft_zero_padding(t_format_specifier *f_spec, long int n, unsigned int base)
{
	ssize_t	err;
	int		nb_digit;

	err = 0;
	nb_digit = ft_count_digits(n, base);
	if (ft_isneg(n) && f_spec->precision)
		err = ft_write_pad(f_spec->precision - nb_digit + 1, '0');
	else if (f_spec->precision)
		err = ft_write_pad(f_spec->precision - nb_digit, '0');
	// else if (ft_isneg(n) && f_spec->width)
	// 	err = ft_write_pad(f_spec->width - nb_digit, '0');
	return (err);
}

ssize_t	ft_zero_padding_u(t_format_specifier *f_spec, unsigned int n, unsigned int base)
{
	ssize_t	err;
	int		nb_digit;

	err = 0;
	nb_digit = ft_count_udigits(n, base);
	if (f_spec->precision)
		err = ft_write_pad(f_spec->precision - nb_digit, '0');
	return (err);
}

ssize_t	ft_zero_padding_p(t_format_specifier *f_spec, uintptr_t n, unsigned int base)
{
	ssize_t	err;
	int		nb_digit;

	err = 0;
	nb_digit = ft_count_udigits(n, base);
	if (f_spec->precision)
		err = ft_write_pad(f_spec->precision - nb_digit, '0');
	if (f_spec->width && ft_strcontain(f_spec->flag, '0'))
		err = ft_write_pad(f_spec->width - nb_digit - 2, '0');
	return (err);
}