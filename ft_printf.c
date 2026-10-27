/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannay <svannay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:47:29 by svannay           #+#    #+#             */
/*   Updated: 2026/10/27 11:14:57 by svannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_splitter(va_list args, char c)
{
	intptr_t	*ptr;
	
	if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		ft_putaddress_fd(ptr);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putubase_fd(va_arg(args, int), 1, LOWERCASE, 10);
	else if (c == 'x')
		ft_puthexnbr_fd(va_arg(args, int), 1, LOWERCASE);
	else if (c == 'X')
		ft_puthexnbr_fd(va_arg(args, int), 1, UPPERCASE);
}

// void	*ft_get_arg(char c, va_list args)
// {
// 	if (c == '%')
// 		return ("%");
// 	else if (c == 'c')
// 		return ((void *)(intptr_t)va_arg(args, int));
// 	else if (c == 's')
// 		return ((void *)va_arg(args, char *));
// 	else if (c == 'p')
// 		return ((void *)va_arg(args, void *));
// 	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
// 		return ((void *)(intptr_t)va_arg(args, int));
// 	return (NULL);
// }

// t_value_type	ft_get_type(char c)
// {
// 	if (c == '%')
// 		return (TYPE_PERCENT);
// 	else if (c == 'c')
// 		return (TYPE_CHAR);
// 	else if (c == 's')
// 		return (TYPE_STR);
// 	else if (c == 'p')
// 		return (TYPE_PTR);
// 	else if (c == 'd')
// 		return (TYPE_DINT);
// 	else if (c == 'i')
// 		return (TYPE_INT);
// 	else if (c == 'u')
// 		return (TYPE_UINT);
// 	else if (c == 'x')
// 		return (TYPE_LOWX);
// 	else if (c == 'X')
// 		return (TYPE_UPX);
// 	return (TYPE_UNDEFINED);
// }

void	ft_free_content(void *content)
{
	free(((t_node_contents *)content)->substr);
	free(content);
}

int	ft_error(t_list **list)
{
	ft_lstclear(list, ft_free_content);
	return (-1);
}

// void	ft_print_node(void *content, va_list args)
// {
// 	ft_putstr_fd(((t_node_contents *)content)->substr, 1);
// 	ft_splitter(args, ((t_node_contents *)content)->type_value);
// }

int	ft_fill_node(t_list **list, char *next, char *substr)
{
	t_node_contents	*node_content;
	t_list			*node;
	
	node = NULL;
	node_content = (t_node_contents *)malloc(sizeof(t_node_contents));
	if (!node_content)
		return (ft_error(list));
	node_content->substr = substr;
	if (!*next)
		node_content->symbol = 0;
	else
		node_content->symbol = *(next + 1);
	node = ft_lstnew(node_content);
	if (!node)
		return (ft_error(list));
	ft_lstadd_back(list, node);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	t_list			*list;
	char			*next;
	t_list			*temp;
	
	va_start(args, s);
	list = NULL;
	while (1)
	{
		next = ft_strchr(s, '%');
		if (!next)
		{
			ft_fill_node(&list, "", ft_substr(s, 0, ft_strlen((char *)s)));
			break ;
		}
		ft_fill_node(&list, next, ft_substr(s, 0, next - s));
		s = next + 2;
	}
	va_end(args);
	temp = list;
	while (temp)
	{
		ft_putstr_fd(((t_node_contents *)temp->content)->substr, 1);
		ft_splitter(args, ((t_node_contents *)temp->content)->symbol);
		temp = temp->next;
	}
	//ft_lstiter(list, ft_print_node);
	ft_lstclear(&list, ft_free_content);
	return (0);
}

int	main(void)
{
	char *str = "string";
	ft_printf("TEST\n");
	ft_printf("%c\n", 'A');
	ft_printf("%s\n", str);
	ft_printf("%p\n", str);
	printf("%p\n", str);
	ft_printf("%d\n", 123);
	ft_printf("%i\n", -123);
	ft_printf("%u\n", 1234);
	ft_printf("%x\n", 123);
	ft_printf("%X\n", 123);
	ft_printf("%%\n");
	ft_printf("hello world %d, i like %s", 42, "cheese");
}


// "bla %d"