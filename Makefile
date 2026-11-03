# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svannay <svannay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 09:45:54 by svannay           #+#    #+#              #
#    Updated: 2026/11/02 14:41:37 by svannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src

SRC =	ft_printf.c \
		src/checks.c \
		src/errors.c \
		src/format_specifier.c \
		src/gets.c \
		src/node.c \
		src/output.c \
		src/utils.c \
		src/convert.c \
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
