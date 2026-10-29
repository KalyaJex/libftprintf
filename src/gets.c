/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:06:32 by svannay           #+#    #+#             */
/*   Updated: 2026/10/29 11:26:04 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_get_flag(t_format_specifier *format_specifier)
{
	while (ft_isflag(*(format_specifier->format)))
	{
		if (!format_specifier->flag)
			format_specifier->flag = *(format_specifier->format);
		(format_specifier->format)++;
	}
}

void	ft_get_length(t_format_specifier *format_specifier)
{
	while (ft_islength(*(format_specifier->format)))
	{
		if (*(format_specifier->format) == format_specifier->length)
			format_specifier->is_length_flag_double = 1;
		else
			format_specifier->length = *(format_specifier->format);
		(format_specifier->format)++;
	}
}

void	ft_get_precision(t_format_specifier *format_specifier)
{
	if (ft_isprecision(*(format_specifier->format)))
	{
		if (*(format_specifier->format + 1) == '*')
		{
			format_specifier->precision_flag = '*';
			(format_specifier->format) += 2;
			return;
		}
		format_specifier->precision = ft_extract_number((format_specifier->format) + 1);
		(format_specifier->format) += ft_count_digits(format_specifier->precision) + 1;
	}
}

void	ft_get_specifier(t_format_specifier *format_specifier)
{
	while (ft_isspecifier(*(format_specifier->format)))
	{
		format_specifier->specifier = *(format_specifier->format);
		(format_specifier->format)++;
	}
}

void	ft_get_width(t_format_specifier *format_specifier)
{
	while (ft_isdigit(*(format_specifier->format))
		|| *(format_specifier->format) == '*')
	{
		if (*(format_specifier->format) == '*')
		{
			format_specifier->width_flag = '*';
			(format_specifier->format)++;
			return ;
		}
		format_specifier->width = ft_extract_number(format_specifier->format);
		format_specifier->format += ft_count_digits(format_specifier->width);
	}
}