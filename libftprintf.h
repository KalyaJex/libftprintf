/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:33 by svannay           #+#    #+#             */
/*   Updated: 2026/10/26 16:17:50 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

typedef enum	e_lettercase 
{
	UPPERCASE,
	LOWERCASE
}				t_lettercase;

typedef enum	e_value_type 
{
	TYPE_INT,
	TYPE_CHAR,
	TYPE_STR,
	TYPE_PTR,
	TYPE_DINT,
	TYPE_UINT,
	TYPE_UPX,
	TYPE_LOWX,
	TYPE_PERCENT,
	TYPE_UNDEFINED
}				t_value_type;

typedef unsigned int t_id_node;

typedef struct		s_node_contents
{
	char			*substr;
	char			symbol;
}					t_node_contents;



int		ft_printf(const char *s, ...);
void	ft_puthexnbr_fd(int n, int fd, t_lettercase lettercase);
//void	ft_putuhexnbr_fd(uintptr_t n, int fd, t_lettercase lettercase);
void	ft_putaddress_fd(void *ptr);
void	ft_putubase_fd(unsigned long int n, int fd, t_lettercase lettercase, unsigned int base_size);

#endif