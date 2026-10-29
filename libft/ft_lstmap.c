/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:33:48 by svannay           #+#    #+#             */
/*   Updated: 2026/10/20 11:01:51 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_current;
	t_list	*new_prev;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	new_prev = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_current = ft_lstnew(f(lst->content));
		if (!new_current)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_prev->next = new_current;
		new_prev = new_prev->next;
		lst = lst->next;
	}
	return (new_lst);
}
