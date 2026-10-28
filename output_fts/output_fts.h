/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_fts.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:14:39 by svannay           #+#    #+#             */
/*   Updated: 2026/10/28 16:26:58 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_FTS_H
# define OUTPUT_FTS_H

#include "../libftprintf.h"

void	ft_putaddress_fd(void *ptr);
void	ft_puthexnbr_fd(int n, int fd, t_lettercase lettercase);
void	ft_putubase_fd(unsigned long int n, 
			int fd,
			t_lettercase lettercase,
			unsigned int base_size);

#endif
