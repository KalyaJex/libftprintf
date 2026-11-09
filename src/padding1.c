/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:11:45 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 16:22:46 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_write_pad(int pads, char pad)
{
	int		index;
	ssize_t	nb_char;
	ssize_t	err;

	index = 0;
	nb_char = 0;
	while (index < pads)
	{
		err = write(1, &pad, 1);
		if (err < 0)
			return (-1);
		nb_char += err;
		index++;
	}
	return (nb_char);
}

ssize_t	ft_left_padding_i_d(t_format_specifier *f_spec, long int n, unsigned int base)
{
	unsigned int	nb_digit;
	ssize_t			err;
	char			pad;

	err = 0;
	nb_digit = ft_count_digits(n, base);
	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	if (!ft_isneg(n) && ft_strcontain(f_spec->flag, '0') && !f_spec->precision_flag)
		pad = '0';
	else
		pad = ' ';
	if (f_spec->precision_flag == '0' && n == 0)
		err = ft_write_pad(f_spec->width, pad);
	else if (ft_isneg(n) && !f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, pad);
	else if (!f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, pad);
	else if (ft_isneg(n) && ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec) - 1, pad);
	else if (f_spec->precision_flag && ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec), pad);
	return (err);
}

ssize_t	ft_left_padding_u(t_format_specifier *f_spec, unsigned int n, unsigned int base)
{
	unsigned int	nb_digit;
	ssize_t			err;
	char			pad;

	err = 0;
	nb_digit = ft_count_udigits(n, base);
	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	if (ft_strcontain(f_spec->flag, '0') && !f_spec->precision_flag)
		pad = '0';
	else
		pad = ' ';
	if (f_spec->precision_flag == '0' && n == 0)
		err = ft_write_pad(f_spec->width, pad);
	else if (!f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, pad);
	else if (ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec), pad);
	return (err);
}

ssize_t	ft_left_padding_x(t_format_specifier *f_spec, unsigned long long int n, unsigned int base)
{
	unsigned int	nb_digit;
	ssize_t			err;
	char			pad;
	int				need_prefix;

	err = 0;
	need_prefix = ft_strcontain(f_spec->flag, '#');
	nb_digit = ft_count_udigits(n, base);
	if (ft_strcontain(f_spec->flag, '-'))
		return (0);
	if (ft_strcontain(f_spec->flag, '0') && !f_spec->precision_flag)
		pad = '0';
	else
		pad = ' ';
	if (f_spec->precision_flag == '0' && n == 0)
		err = ft_write_pad(f_spec->width, pad);
	else if (need_prefix && !f_spec->precision_flag && (nb_digit + 2) < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit - 2, pad);
	else if (!f_spec->precision_flag && nb_digit < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit, pad);
	else if (need_prefix && ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec) - 2, pad);
	else if (ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec), pad);
	return (err);
}

ssize_t	ft_left_padding_p(t_format_specifier *f_spec, uintptr_t n, unsigned int base)
{
	unsigned int	nb_digit;
	ssize_t			err;

	err = 0;
	nb_digit = ft_count_udigits(n, base);
	if (ft_strcontain(f_spec->flag, '-') || ft_strcontain(f_spec->flag, '0'))
		return (0);
	if (n == 0 && f_spec->width > 5)
		err = ft_write_pad(f_spec->width - 5, ' ');
	else if (!f_spec->precision_flag && (nb_digit + 2) < f_spec->width)
		err = ft_write_pad(f_spec->width - nb_digit - 2, ' ');
	else if (ft_get_preci_l(f_spec) < f_spec->width)
		err = ft_write_pad(f_spec->width - ft_get_preci_l(f_spec) - 2, ' ');
	return (err);
}