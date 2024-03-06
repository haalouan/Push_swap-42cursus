# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haalouan <haalouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:59:09 by haalouan          #+#    #+#              #
#    Updated: 2024/03/06 15:26:12 by haalouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCES = push_swap.c check_errors.c stack_utils.c helper_functions1.c helper_functions2.c stack_moves1.c stack_moves2.c  stack_moves3.c sorting.c indexing_stack.c pivote_algo.c
CC = cc 
FLAGS = -Wall -Wextra -Werror
OBJECT = ${SOURCES:.c=.o} 

all : $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o  $@

clean:
	rm -f $(OBJECT)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean