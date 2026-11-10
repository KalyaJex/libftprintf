/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:00:20 by svannay           #+#    #+#             */
/*   Updated: 2026/11/10 11:52:25 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static ssize_t	ft_putnstr_fd(char *s, unsigned int n, int fd)
{
	unsigned int	nb_char;

	nb_char = 0;
	if (!s)
		return (-1);
	while (*s && 0 < n)
	{
		if (ft_putchar_fd(*s, fd) < 0)
			return (-1);
		nb_char++;
		s++;
		n--;
	}
	return (nb_char);
}

static int	ft_check_precision(t_format_specifier *f_spec)
{
	if (f_spec->precision_flag == '0' || ((f_spec->precision_flag == '.' || f_spec->precision_flag == '*') && f_spec->precision >= 0))
		return (1);
	return (0);
}


static ssize_t	ft_write_str(t_format_specifier *f_spec, char *s)
{
	ssize_t		err;

	err = 0;
	if (ft_check_precision(f_spec))
	{
		err = ft_putnstr_fd(s, f_spec->precision, 1);
		if (ft_isneg(err))
			return (-1);
	}
	else
	{
		err = ft_putstr_fd(s, 1);
		if (ft_isneg(err))
			return (-1);
	}
	return (err);
}

ssize_t	ft_output_s(t_format_specifier *f_spec, va_list args)
{
	char		*s;
	ssize_t		nb_char;
	ssize_t		err;

	s = (char *)va_arg(args, char *);
	nb_char = 0;
	err = ft_left_padding_s(f_spec, s);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_write_str(f_spec, s);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	err = ft_right_padding(f_spec, nb_char);
	if (ft_isneg(err))
		return (-1);
	nb_char += err;
	return (nb_char);
}
