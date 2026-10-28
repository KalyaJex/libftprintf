/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_fts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:15:43 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:06:29 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_FTS_H
# define NODE_FTS_H

#include "../libftprintf.h"

int	ft_fill_node(t_list **list, char *next, char *substr, va_list args);
int ft_get_arg(t_node_contents *node, va_list args);
int	ft_init_node(t_node_contents *node, char *str, va_list args);
t_list	*ft_process_args(va_list args, char *s);

#endif
