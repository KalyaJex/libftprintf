/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:19:47 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 15:40:20 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// ssize_t	ft_puthexnbr_fd(int n, int fd, t_lettercase lettercase)
// {
// 	long int	ln;

// 	ln = (long int)n;
// 	if (ln < 0)
// 	{
// 		if (ft_putchar_fd('-', fd) < 0)
// 			return (-1);
// 		ln *= -1;
// 	}
// 	if (ln < 16)
// 	{
// 		if (ft_putchar_fd(ft_getbase(lettercase)[ln % 16], fd) < 0)
// 			return (-1);
// 	}
// 	if (ln >= 16)
// 	{
// 		if (ft_puthexnbr_fd(ln / 16, fd, lettercase) < 0)
// 			return (-1);
// 		if (ft_putchar_fd(ft_getbase(lettercase)[ln % 16], fd) < 0)
// 			return (-1);
// 	}
// }

// ssize_t	ft_putubase_fd(unsigned long int n,
// 		int fd,
// 		t_lettercase lettercase,
// 		unsigned int base_size)
// {
// 	if (n < base_size)
// 	{
// 		if (ft_putchar_fd(ft_getbase(lettercase)[n % base_size], fd) < 0)
// 			return (-1);
// 	}
// 	if (n >= base_size)
// 	{
// 		if (ft_putubase_fd(n / base_size, fd, lettercase, base_size) < 0)
// 			return (-1);
// 		if (ft_putchar_fd(ft_getbase(lettercase)[n % base_size], fd) < 0)
// 			return (-1);
// 	}
// }

// ssize_t	ft_putaddress_fd(void *ptr)
// {
// 	uintptr_t p;

// 	p = (uintptr_t)ptr;
// 	if (ft_putstr_fd("0x", 1) < 0)
// 		return (-1);
// 	if (ft_putubase_fd(p, 1, LOWERCASE, 16) < 0)
// 		return (-1);
// }

ssize_t	ft_output(t_format_specifier *f_spec, va_list args)
{
	ssize_t		err;
	
	if (f_spec->is_gibberish)
		return (ft_putstr_fd(f_spec->og_ptr, 1));
	ft_fetch_width_preci(f_spec, args);
	if (f_spec->specifier == '%')
		err = ft_putchar_fd('%', 1);
	if (f_spec->specifier == 'i' || f_spec->specifier == 'd')
		err = ft_output_i_d(f_spec, args);
	if (f_spec->specifier == 'u')
		err = ft_output_u(f_spec, args);
	if (f_spec->specifier == 'x')
		err = ft_output_lowx(f_spec, args);
	if (f_spec->specifier == 'X')
		err = ft_output_upx(f_spec, args);
	if (f_spec->specifier == 'p')
		err = ft_output_p(f_spec, args);
	if (f_spec->specifier == 'c')
		err = ft_output_c(f_spec, args);
	if (f_spec->specifier == 's')
		err = ft_output_s(f_spec, args);
	return (err);
}

ssize_t	ft_putnbr_base_fd(int n, int fd, unsigned int base)
{
	long int	ln;
	int		nb_digi;
	ssize_t	nb_char;
	ssize_t	error;

	ln = (long int)n;
	nb_char = 0;
	if (ln < 0)
		ln *= -1;
	nb_digi = ft_count_digits(ln, base) - 1;
	while (0 <= nb_digi)
	{
		error = write(fd, &ft_getbase(LOWERCASE)[ln / ft_pow(base, nb_digi)], 1);
		if (0 > error)
			return (-1);
		nb_char += error;
		ln %= ft_pow(base, nb_digi);
		nb_digi--;
	}
	return (nb_char);
}

ssize_t	ft_putunbr_fd(unsigned int n,
			int fd,
			unsigned int base,
			t_lettercase lettercase)
{
	int		nb_digi;
	ssize_t	nb_char;
	ssize_t	error;

	nb_char = 0;
	nb_digi = ft_count_udigits(n, base) - 1;
	while (0 <= nb_digi)
	{
		error = write(fd, &ft_getbase(lettercase)[n / ft_pow(base, nb_digi)], 1);
		if (0 > error)
			return (-1);
		nb_char += error;
		n %= ft_pow(base, nb_digi);
		nb_digi--;
	}
	return (nb_char);
}

ssize_t	ft_putptr_fd(uintptr_t n,
			int fd,
			unsigned int base,
			t_lettercase lettercase)
{
	int		nb_digi;
	ssize_t	nb_char;
	ssize_t	error;

	nb_char = 0;
	nb_digi = ft_count_udigits(n, base) - 1;
	while (0 <= nb_digi)
	{
		error = write(fd, &ft_getbase(lettercase)[n / ft_pow_ptr(base, nb_digi)], 1);
		if (0 > error)
			return (-1);
		nb_char += error;
		n %= ft_pow_ptr(base, nb_digi);
		nb_digi--;
	}
	return (nb_char);
}

ssize_t	ft_putsign_fd(int n, int fd, char *flag, char spec)
{
	ssize_t	error;

	error = 0;
	if (ft_strcontain(flag, '#') && n != 0)
	{
		if (spec == 'x')
			error = write(fd, "0x", 2);
		else if (spec == 'X')
			error = write(fd, "0X", 2);
	}
	else if (spec == 'p')
		error = write(fd, "0x", 2);
	else if (ft_strcontain(flag, ' ') && n > 0)
		error = write(fd, " ", 1);
	else if (ft_strcontain(flag, '+') && n > 0)
		error = write(fd, "+", 1);
	else if (!(spec == 'x' || spec == 'X' || spec == 'u') && n < 0)
		error = write(fd, "-", 1);
	return (error);
}