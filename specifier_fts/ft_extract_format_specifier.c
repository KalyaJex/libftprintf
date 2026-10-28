/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_format_specifier.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:53:32 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 14:53:46 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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