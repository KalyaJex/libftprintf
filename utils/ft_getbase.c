/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:09:04 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:13:07 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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