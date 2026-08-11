# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 17:34:31 by pauhenr2          #+#    #+#              #
#    Updated: 2026/08/11 17:20:34 by pauhenr2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#__________Configurations____________#

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

#___________Source Files_____________#

SRCS = $(SRC_DIR)ft_printf.c \
	$(SRC_DIR)ft_printf_text.c \
	$(SRC_DIR)ft_printf_numbers.c

OBJS = $(SRCS:.c=.o)

#_______________Rules_______________#

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
