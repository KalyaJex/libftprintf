/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_format_specifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:29:09 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 15:29:49 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_format_specifier(t_format_specifier *format_specifier)
{
	if (format_specifier->og_ptr)
		free(format_specifier->og_ptr);
	free(format_specifier);
}
