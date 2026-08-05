# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/23 20:51:14 by pauhenr2          #+#    #+#              #
#    Updated: 2026/08/05 12:04:13 by pauhenr2         ###   ########.fr        #
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
	split.c

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
