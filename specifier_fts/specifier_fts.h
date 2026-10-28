/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_fts.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:52:53 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:01:38 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_FTS_H
# define SPECIFIER_FTS_H

#include "../libftprintf.h"

int		ft_analyse_format_specifier(t_format_specifier *format_specifier);
char	*ft_extract_format_specifier(char *str);
int		ft_extract_number(char *str);
void	ft_get_flag(t_format_specifier *format_specifier);
void	ft_get_length(t_format_specifier *format_specifier);
void	ft_get_precision(t_format_specifier *format_specifier);
void	ft_get_specifier(t_format_specifier *format_specifier);
void	ft_get_width(t_format_specifier *format_specifier);
int		ft_init_format_specifier(t_format_specifier *format_specifier, char* str);

#endif
