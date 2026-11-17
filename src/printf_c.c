/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:36:11 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 14:35:27 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_char_count	*ft_output_c(va_list args, t_char_count *char_count)
{
	char	c;

	if (char_count->error == -1)
		return (char_count);
	c = (unsigned char)va_arg(args, int);
	ft_putchar_fd(c, 1, char_count);
	return (char_count);
}
