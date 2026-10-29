/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:04:31 by svannay           #+#    #+#             */
/*   Updated: 2026/10/29 13:43:26 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_getbase(t_lettercase lettercase)
{
	char	*upper_base;
	char	*lower_base;

	upper_base = "0123456789ABCDEF";
	lower_base = "0123456789abcdef";
	if (lettercase == UPPERCASE)
		return (upper_base);
	else
		return (lower_base);
}

void	ft_free_node_content(void *content)
{
	if (((t_node_contents *)content)->format_specifier)
		ft_free_format_specifier(((t_node_contents *)content)->format_specifier);
	free(((t_node_contents *)content)->substr);
	if (content)
		free(content);
}

void	ft_free_format_specifier(t_format_specifier *format_specifier)
{
	if (format_specifier->og_ptr)
		free(format_specifier->og_ptr);
	free(format_specifier);
}

int	ft_count_digits(long long int n)
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
