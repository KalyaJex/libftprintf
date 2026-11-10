# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svannay <svannay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/06 09:45:54 by svannay           #+#    #+#              #
#    Updated: 2026/11/10 12:47:15 by svannay          ###   ########.fr        #
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
		src/output.c \
		src/utils1.c \
		src/utils2.c \
		src/strings.c \
		src/padding1.c \
		src/padding2.c \
		src/padding3.c \
		src/printf_i_d.c \
		src/printf_u.c \
		src/printf_x.c \
		src/printf_c.c \
		src/printf_s.c \
		src/printf_p.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft

INC_DIR = .
CPPFLAGS = -I$(INC_DIR)

NAME = libftprintf.a

all: $(NAME)

bonus: all

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
