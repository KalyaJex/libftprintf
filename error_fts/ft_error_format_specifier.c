/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_format_specifier.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:59:00 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:59:20 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_fts.h"

int	ft_error_format_specifier(t_format_specifier *format_specifier)
{
	ft_free_format_specifier(format_specifier);
	return (-1);
}