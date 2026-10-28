/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:22:39 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:22:48 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_fts.h"

void	ft_putaddress_fd(void *ptr)
{
	uintptr_t p;

	p = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	ft_putubase_fd(p, 1, LOWERCASE, 16);
}