/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:15:07 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 12:12:59 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_error_format_specifier(t_format_specifier *format_specifier)
{
	ft_free_format_specifier(format_specifier);
	return (-1);
}
