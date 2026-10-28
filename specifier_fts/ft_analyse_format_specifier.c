/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_format_specifier.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:10:44 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:11:07 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_fts.h"

int	ft_analyse_format_specifier(t_format_specifier *format_specifier)
{
	ft_get_flag(format_specifier);
	ft_get_width(format_specifier);
	ft_get_precision(format_specifier);
	ft_get_length(format_specifier);
	ft_get_specifier(format_specifier);
	if (!*format_specifier->format)
		return (0);
	return (-1);
}