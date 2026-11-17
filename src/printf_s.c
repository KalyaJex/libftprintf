/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:00:20 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:14:52 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_check_precision(t_format_specifier *f_spec)
{
	if (f_spec->precision_flag == '0'
		|| ((f_spec->precision_flag == '.' || f_spec->precision_flag == '*')
			&& f_spec->precision >= 0))
		return (1);
	return (0);
}

t_char_count	*ft_output_s(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count)
{
	char		*s;

	if (char_count->error == -1)
		return (char_count);
	s = (char *)va_arg(args, char *);
	if (ft_check_precision(f_spec))
		ft_putnstr(s, f_spec->precision, char_count);
	else
		ft_putstr_fd(s, 1, char_count);
	return (char_count);
}
