/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:08:44 by svannay           #+#    #+#             */
/*   Updated: 2026/11/09 16:14:05 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int	ft_analyse_format_specifier(t_format_specifier *f_spec)
{	
	if (*(f_spec->format) == '%')
	{
		f_spec->specifier = '%';
		return (0);
	}
	if(ft_get_flag(f_spec) < 0)
		return (-1);
	if(ft_get_width(f_spec) < 0)
		return (-1);
	if(ft_get_precision(f_spec) < 0)
		return (-1);
	if(ft_get_length(f_spec) < 0)
		return (-1);
	if(ft_get_specifier(f_spec) < 0)
		return (-1);
	if (!*f_spec->format)
		return (0);
	return (-1);
}

int	ft_extract_number(char *str)
{
	unsigned int	index;
	char			*number;
	int				result;

	index = 0;
	while(ft_isdigit(str[index]))
	{
		index++;
	}
	number = ft_substr(str, 0, index);
	result = ft_atoi(number);
	free(number);
	return (result);
}

int	ft_init_format_specifier(t_format_specifier *format_specifier, char* str)
{
	int	error;
	int	format_specifier_l;

	error = 0;
	format_specifier->format = ft_extract_format(str, ft_check_next_spec);
	format_specifier->og_ptr = format_specifier->format;
	//printf("[%s] [%s]\n", format_specifier->format, str);
	format_specifier_l = (int)ft_strlen(format_specifier->format);
	//printf("%d\n", format_specifier_l);
	if (!format_specifier->format)
		return (-1);
	format_specifier->flag = NULL;
	format_specifier->width = 0;
	format_specifier->width_flag = 0;
	format_specifier->length = NULL;
	format_specifier->precision = 0;
	format_specifier->precision_flag = 0;
	format_specifier->specifier = 0;
	format_specifier->is_gibberish = 0;
	error += ft_analyse_format_specifier(format_specifier);
	if (error < 0)
	{
		format_specifier->is_gibberish = 1;
		return (format_specifier_l);
	}
	return (format_specifier_l);
}
