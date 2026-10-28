/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format_specifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:00:31 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:01:23 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_fts.h"

int	ft_init_format_specifier(t_format_specifier *format_specifier, char* str)
{
	int	error;
	int	format_specifier_l;

	error = 0;
	format_specifier->format = ft_extract_format_specifier(str);
	format_specifier->og_ptr = format_specifier->format;
	format_specifier_l = (int)ft_strlen(format_specifier->format);
	if (!format_specifier->format)
		return (-1);
	format_specifier->flag = 0;
	format_specifier->width = 0;
	format_specifier->width_flag = 0;
	format_specifier->is_length_flag_double = 0;
	format_specifier->length = 0;
	format_specifier->precision = 0;
	format_specifier->precision_flag = 0;
	format_specifier->specifier = 0;
	error += ft_analyse_format_specifier(format_specifier);
	if (error < 0)
	{
		ft_free_format_specifier(format_specifier);
		return (-1);
	}
	return (format_specifier_l);
}