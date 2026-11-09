/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:14:52 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 14:00:19 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_right_padding(t_format_specifier *f_spec, ssize_t nb_char)
{
	ssize_t	err;

	err = 0;
	if (f_spec->precision > f_spec->width)
		return (0);
	if (ft_strcontain(f_spec->flag, '-') && f_spec->specifier == 'p')
		err = ft_write_pad(f_spec->width - nb_char, ' ');
	if (ft_strcontain(f_spec->flag, '-'))
		err = ft_write_pad(f_spec->width - nb_char, ' ');
	return (err);
}
