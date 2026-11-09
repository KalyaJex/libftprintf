/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:03:05 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 14:39:00 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static ssize_t	ft_before(t_format_specifier *f_spec, long int n)
{
	ssize_t		nb_char;
	ssize_t		err;

	nb_char = 0;
	err = ft_left_padding_x(f_spec, n, BASE16);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_putsign_fd(n, 1, f_spec->flag, f_spec->specifier);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_zero_padding_u(f_spec, n, BASE16);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}

ssize_t	ft_output_upx(t_format_specifier *f_spec, va_list args)
{
	long int	n;
	ssize_t		nb_char;
	ssize_t		err;

	nb_char = 0;
	n = (long int)va_arg(args, long int);
	err = ft_before(f_spec, n);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_putunbr_fd(n, 1, BASE16, UPPERCASE);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_right_padding(f_spec, nb_char);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}

ssize_t	ft_output_lowx(t_format_specifier *f_spec, va_list args)
{
	long int	n;
	ssize_t		nb_char;
	ssize_t		err;

	nb_char = 0;
	n = (long int)va_arg(args, long int);
	err = ft_before(f_spec, n);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_putunbr_fd(n, 1, BASE16, LOWERCASE);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_right_padding(f_spec, nb_char);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}
