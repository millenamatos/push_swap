# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/23 20:51:14 by pauhenr2          #+#    #+#              #
#    Updated: 2026/08/10 23:48:24 by pauhenr2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#___________CONFIGURATION___________#

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

#___________SOURCE FILES____________#

SRCS = main.c \
	stack_utils.c \
	parser.c \
	parser_numbers.c \
	disorder.c \
	split.c \
	swap.c \
	push.c \
	rotate.c \
	rotate_reverse.c \
	simple_sort.c \
	medium_utils.c \
	medium_utils_two.c \
	medium_sort.c

OBJS = $(SRCS:.c=.o)

#_______________RULES_______________#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
