/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:54:55 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 14:55:24 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_fts.h"

void	ft_get_flag(t_format_specifier *format_specifier)
{
	while (ft_isflag(*(format_specifier->format)))
	{
		if (!format_specifier->flag)
			format_specifier->flag = *(format_specifier->format);
		(format_specifier->format)++;
	}
}