/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 10:48:42 by svannay           #+#    #+#             */
/*   Updated: 2026/11/05 11:39:30 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ultoa(unsigned long int ln, unsigned int base, t_lettercase lettercase)
{
	int			nb_digits;
	char		*str;

	nb_digits = ft_count_udigits(ln, base);
	//printf("%d\n", nb_digits);
	str = malloc((nb_digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (ln == 0)
		return (ft_add_zero(str));
	*(str + nb_digits) = '\0';
	while (0 < ln)
	{
		*(str + nb_digits-- - 1) = ft_getbase(lettercase)[ln % base];
		ln /= base;
	}
	return (str);
}