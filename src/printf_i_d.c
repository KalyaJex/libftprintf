/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_i_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:07:19 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 15:10:30 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static ssize_t	ft_before(t_format_specifier *f_spec, long int n)
{
	ssize_t		nb_char;
	ssize_t		err;

	nb_char = 0;
	err = ft_left_padding_i_d(f_spec, n, BASE10);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_putsign_fd(n, 1, f_spec->flag, f_spec->specifier);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_zero_padding(f_spec, n, BASE10);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}

ssize_t	ft_output_i_d(t_format_specifier *f_spec, va_list args)
{
	int	n;
	ssize_t		nb_char;
	ssize_t		err;

	nb_char = 0;
	n = (int)va_arg(args, int);
	err = ft_before(f_spec, n);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_putnbr_base_fd(n, 1, BASE10);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_right_padding(f_spec, nb_char);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}
