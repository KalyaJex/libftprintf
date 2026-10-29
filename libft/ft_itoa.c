/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:45:55 by svannay           #+#    #+#             */
/*   Updated: 2026/10/20 11:23:05 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_digits(long int n)
{
	int			count;
	int			is_negative;

	is_negative = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	count = 0;
	while (0 < n)
	{
		n /= 10;
		count++;
	}
	return (count + is_negative);
}

static char	*ft_add_zero(char *str)
{
	*str = '0';
	*(str + 1) = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long int	l_n;
	int			nb_digits;
	char		*str;

	l_n = n;
	nb_digits = ft_count_digits(l_n);
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
		*(str + nb_digits-- - 1) = (l_n % 10) + '0';
		l_n /= 10;
	}
	return (str);
}
