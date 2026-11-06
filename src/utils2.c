/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:01:23 by svannay           #+#    #+#             */
/*   Updated: 2026/11/06 12:51:21 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_udigits(unsigned long long int n, unsigned int base)
{
	int			count;
	int			is_negative;

	is_negative = 0;
	if (n == 0)
		return (1);
	count = 0;
	while (0 < n)
	{
		n /= base;
		count++;
	}
	return (count + is_negative);
}

int ft_pow(int n, unsigned int pow)
{
	int total;
	
	total = 1;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (n);
	while (pow > 0)
	{
		total *= n;
		pow--;
	}
	return (total);
}