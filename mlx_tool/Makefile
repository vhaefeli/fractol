# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 13:42:13 by vhaefeli          #+#    #+#              #
#    Updated: 2022/04/25 13:57:46 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = mlx_tools.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	colorshade.c/
		
		
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

