/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:01:24 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:01:44 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_fts.h"

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
