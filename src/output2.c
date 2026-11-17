/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:19:47 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:11:01 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_char_count	*ft_putptr(uintptr_t n,
					unsigned int base,
					t_lettercase lettercase,
					t_char_count *char_count)
{
	int		nb_digi;

	if (char_count->error == -1)
		return (char_count);
	nb_digi = ft_count_udigits(n, base) - 1;
	while (0 <= nb_digi)
	{
		if (ft_putchar_fd(
				ft_getbase(lettercase)[n / ft_pow_ptr(base, nb_digi)],
			1, char_count)->error == -1)
			return (char_count);
		n %= ft_pow_ptr(base, nb_digi);
		nb_digi--;
	}
	return (char_count);
}

t_char_count	*ft_putsign(int n,
					t_format_specifier *f_spec,
					t_char_count *char_count)
{
	if (char_count->error == -1)
		return (char_count);
	if (ft_strcontain(f_spec->flag, ' ') && n >= 0)
		return (ft_putchar_fd(' ', 1, char_count));
	else if (ft_strcontain(f_spec->flag, '+') && n > 0)
		return (ft_putchar_fd('+', 1, char_count));
	else if (!(f_spec->specifier == 'x' || f_spec->specifier == 'X'
			|| f_spec->specifier == 'u') && n < 0)
		return (ft_putchar_fd('-', 1, char_count));
	return (char_count);
}

t_char_count	*ft_putprefix(uintptr_t n,
					t_format_specifier *f_spec,
					t_char_count *char_count)
{
	if (char_count->error == -1)
		return (char_count);
	if (ft_strcontain(f_spec->flag, '#') && n != 0)
	{
		if (f_spec->specifier == 'x')
			return (ft_putstr_fd("0x", 1, char_count));
		else if (f_spec->specifier == 'X')
			return (ft_putstr_fd("0X", 1, char_count));
	}
	else if (f_spec->specifier == 'p' && n != 0)
		return (ft_putstr_fd("0x", 1, char_count));
	return (char_count);
}

t_char_count	*ft_putnstr(char *s, unsigned int n, t_char_count *char_count)
{
	if (char_count->error == -1)
		return (char_count);
	if (!s)
		return (char_count->error = -1, char_count);
	while (*s && 0 < n)
	{
		if (ft_putchar_fd(*s, 1, char_count)->error == -1)
			return (char_count);
		s++;
		n--;
	}
	return (char_count);
}
