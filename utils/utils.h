/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:45:03 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:17:18 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "../libftprintf.h"

int		ft_count_digits(long int n);
int		ft_isflag(int c);
int		ft_islength(int c);
int		ft_isprecision(int c);
int		ft_isspecifier(int c);
void	ft_free_format_specifier(t_format_specifier *format_specifier);
void	ft_free_node_content(void *content);
char	*ft_getbase(t_lettercase lettercase);

#endif
