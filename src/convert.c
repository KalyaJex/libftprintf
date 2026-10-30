/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:35:34 by svannay           #+#    #+#             */
/*   Updated: 2026/10/30 15:02:06 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_add_zero(char *str)
{
	*str = '0';
	*(str + 1) = '\0';
	return (str);
}

char	*ft_itoa(int n, unsigned int base, t_lettercase lettercase)
{
	long int	l_n;
	int			nb_digits;
	char		*str;

	l_n = n;
	nb_digits = ft_count_digits(l_n, base);
	str = malloc((nb_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (l_n == 0)
		return (ft_add_zero(str));
	if (l_n < 0)
	{
		l_n *= -1;
		*str = '-';
	}
	*(str + nb_digits) = '\0';
	while (0 < l_n)
	{
		*(str + nb_digits-- - 1) = ft_getbase(lettercase)[l_n % base];
		l_n /= base;
	}
	return (str);
}

char	*ft_ltoa(long int ln, unsigned int base, t_lettercase lettercase)
{
	long long int	ll_n;
	int			nb_digits;
	char		*str;

	ll_n = ln;
	nb_digits = ft_count_digits(ll_n, base);
	str = malloc((nb_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (ll_n == 0)
		return (ft_add_zero(str));
	if (ll_n < 0)
	{
		ll_n *= -1;
		*str = '-';
	}
	*(str + nb_digits) = '\0';
	while (0 < ll_n)
	{
		*(str + nb_digits-- - 1) = ft_getbase(lettercase)[ll_n % base];
		ll_n /= base;
	}
	return (str);
}

char	*ft_ctos(char c)
{
	char		*str;
	
	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0'; 
	return (str);
}

char	*ft_utoa(unsigned int n, unsigned int base, t_lettercase lettercase)
{
	int			nb_digits;
	char		*str;

	nb_digits = ft_count_digits(n, base);
	str = malloc((nb_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_add_zero(str));
	*(str + nb_digits) = '\0';
	while (0 < n)
	{
		*(str + nb_digits-- - 1) = ft_getbase(lettercase)[n % base];
		n /= base;
	}
	return (str);
}