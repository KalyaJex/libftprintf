/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:54:12 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 14:54:20 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
