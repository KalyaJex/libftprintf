/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:10:25 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:12:17 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

#include "libftprintf.h"

typedef enum			e_lettercase 
{
	UPPERCASE,
	LOWERCASE
}						t_lettercase;

typedef enum			e_value_type 
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
}						t_value_type;

typedef enum			e_flags
{
	FLAG_LEFT_JUSTIFY,
	FLAG_SIGN,
	FLAG_SPACE,
	FLAG_HASHTAG,
	FLAG_ZERO
}						t_flags;

typedef unsigned int	t_id_node;

typedef struct			s_format_specifier
{
	char				*format;
	char				*og_ptr;
	char				flag;
	unsigned int		width;
	char				width_flag;
	unsigned int		precision;
	char				precision_flag;
	char				length;
	int					is_length_flag_double;
	char				specifier;
}						t_format_specifier;

typedef union			u_print_value
{
	int					i;
	char				c;
	char 				*s;
	intptr_t			*p;
}						t_print_value;

typedef struct			s_node_contents
{
	char				*substr;
	t_print_value		print_value;
	t_format_specifier	*format_specifier;
}						t_node_contents;

#endif
