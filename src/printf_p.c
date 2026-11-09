/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:02:00 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 15:14:29 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static ssize_t	ft_before(t_format_specifier *f_spec, uintptr_t p)
{
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	err = ft_left_padding_p(f_spec, p, BASE16);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	if (p != 0)
	{
		err = ft_putsign_fd(p, 1, f_spec->flag, f_spec->specifier);
		if ( ft_isneg(err))
			return (-1);
		nb_char += err;
	}
	err = ft_zero_padding_p(f_spec, p, BASE16);
	if (p != 0 && ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}

static ssize_t	ft_write_address(uintptr_t p)
{
	ssize_t		err;

	err = 0;	
	if (p == 0)
	{
		err = ft_putstr_fd("(nil)", 1);
		if (ft_isneg(err))
			return (-1);
	}
	else
	{
		err = ft_putptr_fd(p, 1, BASE16, LOWERCASE);
		if (ft_isneg(err))
			return (-1);
	}
	return (err);
}

ssize_t	ft_output_p(t_format_specifier *f_spec, va_list args)
{
	uintptr_t	p;
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	p = (uintptr_t)va_arg(args, void *);
	err = ft_before(f_spec, p);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_write_address(p);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_right_padding(f_spec, nb_char);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}