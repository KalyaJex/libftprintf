/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:15:07 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:15:05 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_error_format_specifier(t_format_specifier *format_specifier,
			t_char_count *char_count)
{
	char_count->error = -1;
	ft_free_format_spec(format_specifier);
}
