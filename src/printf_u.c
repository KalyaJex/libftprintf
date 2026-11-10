/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:06:14 by svannay           #+#    #+#             */
/*   Updated: 2026/11/10 11:34:28 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static ssize_t	ft_before(t_format_specifier *f_spec, unsigned int n)
{
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	err = ft_left_padding_u(f_spec, n, BASE10);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_zero_padding_u(f_spec, n, BASE10);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}

static int	ft_check_zero_precision(t_format_specifier *f_spec, unsigned int n)
{
	if (n == 0)
	{
		if (f_spec->precision_flag == '0' || (f_spec->precision_flag == '.' && f_spec->precision == 0))
			return (1);
	}
	return (0);
}

ssize_t	ft_output_u(t_format_specifier *f_spec, va_list args)
{
	unsigned int	n;
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	n = (unsigned int)va_arg(args, unsigned int);
	err = ft_before(f_spec, n);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	if (!ft_check_zero_precision(f_spec, n))
	{
		err = ft_putunbr_fd(n, 1, BASE10, LOWERCASE);
		if (ft_isneg(err))
			return (-1);
		nb_char += err;
	}
	err = ft_right_padding(f_spec, nb_char);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}