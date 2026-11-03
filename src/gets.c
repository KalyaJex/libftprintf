/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:06:32 by svannay           #+#    #+#             */
/*   Updated: 2026/11/03 11:04:45 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_get_flag(t_format_specifier *format_specifier)
{
	if (!ft_isflag(*(format_specifier->format)))
		return (-1);
	if (ft_isflag(*(format_specifier->format)))
	{
		format_specifier->flag = ft_extract_substr(format_specifier->format, ft_isflag);
		(format_specifier->format) += ft_strlen(format_specifier->flag);
	}
	return (0);
}

int	ft_get_length(t_format_specifier *format_specifier)
{
	if (!ft_islength(*(format_specifier->format)))
		return (-1);
	while (ft_islength(*(format_specifier->format)))
	{
		if (*(format_specifier->format) == format_specifier->length)
			format_specifier->is_length_flag_double = 1;
		else
			format_specifier->length = *(format_specifier->format);
		(format_specifier->format)++;
	}
	return (0);
}

int	ft_get_precision(t_format_specifier *format_specifier)
{
	if (!ft_isprecision(*(format_specifier->format)))
		return (-1);
	if (ft_isprecision(*(format_specifier->format)))
	{
		if (*(format_specifier->format + 1) == '*')
		{
			format_specifier->precision_flag = '*';
			(format_specifier->format) += 2;
			return;
		}
		format_specifier->precision = ft_extract_number((format_specifier->format) + 1);
		(format_specifier->format) += ft_count_digits(format_specifier->precision, BASE10) + 1;
	}
	return (0);
}

int	ft_get_specifier(t_format_specifier *format_specifier)
{
	if (!ft_isspecifier(*(format_specifier->format)))
		return (-1);
	while (ft_isspecifier(*(format_specifier->format)))
	{
		format_specifier->specifier = *(format_specifier->format);
		(format_specifier->format)++;
	}
	return (0);
}

void	ft_get_width(t_format_specifier *format_specifier)
{
	if (!ft_isdigit(*(format_specifier->format)))
		return (-1);
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
		format_specifier->format += ft_count_digits(format_specifier->width, BASE10);
	}
	return (0);
}