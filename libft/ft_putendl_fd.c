/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:35:08 by svannay           #+#    #+#             */
/*   Updated: 2026/11/17 11:36:35 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_char_count	*ft_putendl_fd(char *s, int fd, t_char_count *char_count)
{
	if (char_count->error == -1)
		return (char_count);
	if (ft_putstr_fd(s, fd, char_count)->error == -1)
		return (char_count);
	if (ft_putchar_fd('\n', fd, char_count)->error == -1)
		return (char_count);
	return (char_count);
}
