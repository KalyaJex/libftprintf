/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:06:32 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 16:13:41 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_get_flag(t_format_specifier *format_spec)
{
	if (!(ft_isflag(*(format_spec->format))
			|| ft_isprecision(*(format_spec->format))
			|| ft_islength(*(format_spec->format))
			|| ft_iswidth(*(format_spec->format))
			|| ft_isspecifier(*(format_spec->format))))
		return (-1);
	if (ft_isflag(*(format_spec->format)))
	{
		format_spec->flag = ft_extract_subspecifier(format_spec->format,
				ft_isflag);
		(format_spec->format) += ft_strlen(format_spec->flag);
	}
	return (0);
}

int	ft_get_length(t_format_specifier *format_spec)
{
	if (!(ft_islength(*(format_spec->format))
			|| ft_isspecifier(*(format_spec->format))))
		return (-1);
	while (ft_islength(*(format_spec->format)))
	{
		format_spec->length = ft_extract_subspecifier(format_spec->format,
				ft_islength);
		(format_spec->format) += ft_strlen(format_spec->length);
	}
	return (0);
}

int	ft_get_precision(t_format_specifier *f_spec)
{
	if (!(ft_isprecision(*(f_spec->format)) || ft_islength(*(f_spec->format))
			|| ft_isspecifier(*(f_spec->format))))
		return (-1);
	if (ft_isprecision(*(f_spec->format)))
	{
		if (*(f_spec->format + 1) == '*')
		{
			f_spec->precision_flag = '*';
			(f_spec->format) += 2;
			return (0);
		}
		if (ft_isdigit(*(f_spec->format + 1)))
		{
			f_spec->precision = ft_extract_number((f_spec->format) + 1);
			(f_spec->format) += ft_count_digits(f_spec->precision, BASE10) + 1;
			f_spec->precision_flag = '.';
		}
		else
		{
			f_spec->precision_flag = '0';
			f_spec->format++;
		}
	}
	return (0);
}

int	ft_get_specifier(t_format_specifier *format_spec)
{
	if (!ft_isspecifier(*(format_spec->format)))
		return (-1);
	while (ft_isspecifier(*(format_spec->format)))
	{
		format_spec->specifier = *(format_spec->format);
		(format_spec->format)++;
	}
	return (0);
}

int	ft_get_width(t_format_specifier *format_spec)
{
	if (!(ft_isprecision(*(format_spec->format))
			|| ft_islength(*(format_spec->format))
			|| ft_iswidth(*(format_spec->format))
			|| ft_isspecifier(*(format_spec->format))))
		return (-1);
	while (ft_iswidth(*(format_spec->format)))
	{
		if (*(format_spec->format) == '*')
		{
			format_spec->width_flag = '*';
			(format_spec->format)++;
			return (0);
		}
		format_spec->width = ft_extract_number(format_spec->format);
		format_spec->format += ft_count_digits(format_spec->width, BASE10);
	}
	return (0);
}

//int	ft_get_percent()
