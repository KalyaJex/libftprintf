/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:36:11 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 14:01:09 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_output_c(t_format_specifier *f_spec, va_list args)
{
	char	c;
	ssize_t	nb_char;
	ssize_t	err;

	c = (unsigned char)va_arg(args, int);
	nb_char = 0;
	err = ft_left_padding_c(f_spec);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_putchar_fd(c, 1);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_right_padding(f_spec, 1);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}
