# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svannay <svannay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 09:45:54 by svannay           #+#    #+#              #
#    Updated: 2026/11/05 11:05:01 by svannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src

SRC =	ft_printf.c \
		src/checks1.c \
		src/checks2.c \
		src/errors.c \
		src/format_specifier.c \
		src/gets.c \
		src/node.c \
		src/output.c \
		src/utils1.c \
		src/utils2.c \
		src/convert1.c \
		src/convert2.c \
		src/list.c \
		src/strings.c

OBJ = $(SRC:.c=.o)

LIBFT = libft

INC_DIR = .
CPPFLAGS = -I$(INC_DIR)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all


.PHONY: all clean fclean re
