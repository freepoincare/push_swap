# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunkim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 14:21:53 by eunkim            #+#    #+#              #
#    Updated: 2025/05/14 14:21:55 by eunkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

GNL_DIR = ./get_next_line

SRC_COMMON = manage_args.c \
	stack.c \
	ft_split.c \
	ft_atol.c \
	ft_lst.c \
	utils.c \
	instr_optimize.c \
	instr_utils.c \
	oper_swap.c \
	oper_push.c \
	oper_rotate.c \
	oper_rrotate.c \
	turk_sort_utils.c \
	turk_sort.c \
	turk_sort_enhanced.c \
	sort_arr.c \
	sort_stack_utils.c \
	sort_small_stack.c \
	sort_big_stack.c \

SRC_GNL = $(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

SRC_PUSH_SWAP = $(SRC_COMMON) push_swap.c
SRC_CHECKER = $(SRC_COMMON) checker.c $(SRC_GNL)

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ_PUSH_SWAP)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
