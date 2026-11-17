/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:19:47 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 16:10:33 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_char_count	*ft_output_percent(t_char_count *char_count)
{
	if (char_count->error == -1)
		return (char_count);
	ft_putchar_fd('%', 1, char_count);
	return (char_count);
}

static t_char_count	*ft_output_giberish(char *str, t_char_count *char_count)
{
	if (char_count->error == -1)
		return (char_count);
	ft_putstr_fd(str, 1, char_count);
	return (char_count);
}

t_char_count	*ft_output(t_format_specifier *f_spec,
					va_list args, t_char_count *char_count)
{
	if (f_spec->is_gibberish)
		return (ft_output_giberish(f_spec->og_ptr, char_count));
	if (f_spec->specifier == '%')
		return (ft_output_percent(char_count));
	if (f_spec->specifier == 'i' || f_spec->specifier == 'd')
		return (ft_output_i_d(f_spec, args, char_count));
	if (f_spec->specifier == 'u')
		return (ft_output_u(f_spec, args, char_count));
	if (f_spec->specifier == 'x')
		return (ft_output_lowx(f_spec, args, char_count));
	if (f_spec->specifier == 'X')
		return (ft_output_upx(f_spec, args, char_count));
	if (f_spec->specifier == 'p')
		return (ft_output_p(f_spec, args, char_count));
	if (f_spec->specifier == 'c')
		return (ft_output_c(args, char_count));
	if (f_spec->specifier == 's')
		return (ft_output_s(f_spec, args, char_count));
	return (char_count);
}

t_char_count	*ft_putnbr_base(int n,
					unsigned int base,
					t_char_count *char_count)
{
	long int	ln;
	int			nb_digi;

	if (char_count->error == -1)
		return (char_count);
	ln = (long int)n;
	if (ln < 0)
		ln *= -1;
	nb_digi = ft_count_digits(ln, base) - 1;
	while (0 <= nb_digi)
	{
		if (ft_putchar_fd(
				ft_getbase(LOWERCASE)[ln / ft_pow(base, nb_digi)],
			1, char_count)->error == -1)
			return (char_count);
		ln %= ft_pow(base, nb_digi);
		nb_digi--;
	}
	return (char_count);
}

t_char_count	*ft_putunbr(unsigned int n,
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
				ft_getbase(lettercase)[n / ft_pow(base, nb_digi)],
			1, char_count)->error == -1)
			return (char_count);
		n %= ft_pow(base, nb_digi);
		nb_digi--;
	}
	return (char_count);
}
