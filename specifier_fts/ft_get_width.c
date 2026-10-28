/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:00:00 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:00:14 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_fts.h"

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
