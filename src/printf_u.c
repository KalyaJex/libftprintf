/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:06:14 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 15:13:17 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_output_u(t_format_specifier *f_spec, va_list args)
{
	unsigned int	n;
	ssize_t		nb_char;
	ssize_t		err;
	
	nb_char = 0;	
	n = (unsigned int)va_arg(args, unsigned int);
	err = ft_left_padding_u(f_spec, n, BASE10);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_zero_padding_u(f_spec, n, BASE10);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_putunbr_fd(n, 1, BASE10, LOWERCASE);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_right_padding(f_spec, nb_char);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}