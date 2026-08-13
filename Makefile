# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/23 20:51:14 by pauhenr2          #+#    #+#              #
#    Updated: 2026/08/12 22:34:20 by pauhenr2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#___________CONFIGURATION___________#

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

#_____________FT_PRINTF_____________#

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
INCLUDES = -I. -I$(PRINTF_DIR)

#___________SOURCE FILES____________#

SRCS = main.c \
	stack_utils.c \
	parser.c \
	parser_numbers.c \
	disorder.c \
	bench.c \
	sort_stack.c
	split.c \
	swap.c \
	push.c \
	rotate.c \
	rotate_reverse.c \
	simple_sort.c \
	medium_utils.c \
	medium_utils_two.c \
	medium_sort.c \
	complex_sort.c

OBJS = $(SRCS:.c=.o)

#_______________RULES_______________#

all: $(PRINTF) $(NAME)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
