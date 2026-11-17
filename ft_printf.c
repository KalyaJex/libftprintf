/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:29 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:19:05 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_process_spec(char *str, va_list args, t_char_count *char_count)
{
	t_format_specifier	*f_spec;
	int					format_l;

	f_spec = (t_format_specifier *)malloc(sizeof(t_format_specifier));
	if (!f_spec)
	{
		char_count->error = -1;
		return (-1);
	}
	if (ft_isneg(ft_init_format_specifier(f_spec, str + 1))
		|| ft_isneg(ft_output(f_spec, args, char_count)->error))
	{
		ft_error_format_specifier(f_spec, char_count);
		return (-1);
	}
	format_l = ft_strlen(f_spec->og_ptr);
	ft_free_format_spec(f_spec);
	return (format_l);
}

static void	ft_process_str(char *str, va_list args, t_char_count *char_count)
{
	int	format_l;

	while (*str)
	{
		format_l = 0;
		if (*str == '%')
		{
			format_l = ft_process_spec(str, args, char_count);
			if (ft_isneg(format_l))
				return ;
		}
		else
		{
			if (ft_isneg(ft_putchar_fd(*str, 1, char_count)->error))
			{
				char_count->error = -1;
				return ;
			}
		}
		str += format_l + 1;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	int				size;
	t_char_count	*char_count;

	char_count = malloc(sizeof(char_count));
	if (!char_count)
		return (-1);
	ft_init_char_count(&char_count);
	va_start(args, s);
	ft_process_str((char *)s, args, char_count);
	va_end(args);
	if (char_count->error == -1)
		return (free(char_count), -1);
	size = char_count->nb;
	free(char_count);
	return (size);
}
