/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:08:44 by svannay           #+#    #+#             */
/*   Updated: 2026/10/30 12:40:45 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_analyse_format_specifier(t_format_specifier *format_specifier)
{
	ft_get_flag(format_specifier);
	ft_get_width(format_specifier);
	ft_get_precision(format_specifier);
	ft_get_length(format_specifier);
	ft_get_specifier(format_specifier);
	if (!*format_specifier->format)
		return (0);
	return (-1);
}

char	*ft_extract_format_specifier(char *str)
{
	unsigned int	count;

	count = 0;
	while(*str)
	{
		if (ft_isspecifier(*str))
			break ;
		str++;
		count++;
	}
	return (ft_substr(str, 0, count + 1));
}

int	ft_extract_number(char *str)
{
	unsigned int	count;
	char			*number;
	int				result;

	count = 0;
	while(ft_isdigit(*str))
	{
		str++;
		count++;
	}
	number = ft_substr(str, 0, count);
	result = ft_atoi(number);
	free(number);
	return (result);
}

int	ft_init_format_specifier(t_format_specifier *format_specifier, char* str)
{
	int	error;
	int	format_specifier_l;

	error = 0;
	format_specifier->format = ft_extract_format_specifier(str);
	format_specifier->og_ptr = format_specifier->format;
	//printf("%s", format_specifier->og_ptr);
	format_specifier_l = (int)ft_strlen(format_specifier->format);
	if (!format_specifier->format)
		return (-1);
	format_specifier->flag = 0;
	format_specifier->width = 0;
	format_specifier->width_flag = 0;
	format_specifier->is_length_flag_double = 0;
	format_specifier->length = 0;
	format_specifier->precision = 0;
	format_specifier->precision_flag = 0;
	format_specifier->specifier = 0;
	error += ft_analyse_format_specifier(format_specifier);
	if (error < 0)
	{
		ft_free_format_specifier(format_specifier);
		return (-1);
	}
	return (format_specifier_l);
}
