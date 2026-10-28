/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:00:35 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:00:45 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_fts.h"

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