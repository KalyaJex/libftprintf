# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svannay <svannay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 09:45:54 by svannay           #+#    #+#              #
#    Updated: 2026/10/28 16:42:39 by svannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCE =	ft_printf.c utils/ft_count_digits.c utils/ft_free_format_specific.c\
			utils/ft_free_node_content.c
			utils/
			utils/
			utils/
			utils/
			utils/
			utils/
			utils/
			utils/
OBJECTS = $(SOURCE:.c=.o)

INC_DIR = .
CPPFLAGS = -I$(INC_DIR)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
	make clean

.PHONY: all clean fclean re
