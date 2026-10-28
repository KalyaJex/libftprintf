/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:44:26 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:29:45 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digits(long int n)
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