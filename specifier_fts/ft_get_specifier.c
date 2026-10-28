/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:02:11 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:02:23 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_fts.h"

void	ft_get_specifier(t_format_specifier *format_specifier)
{
	while (ft_isspecifier(*(format_specifier->format)))
	{
		format_specifier->specifier = *(format_specifier->format);
		(format_specifier->format)++;
	}
}