/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:02:00 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:14:07 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_char_count	*ft_output_p(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count)
{
	uintptr_t		p;

	if (char_count->error == -1)
		return (char_count);
	p = (uintptr_t)va_arg(args, void *);
	if (p != 0)
		ft_putprefix(p, f_spec, char_count);
	if (p == 0)
		ft_putstr_fd("(nil)", 1, char_count);
	else
		ft_putptr(p, BASE16, LOWERCASE, char_count);
	return (char_count);
}
