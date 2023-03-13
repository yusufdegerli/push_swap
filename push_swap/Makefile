# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydegerli <ydegerli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 18:02:28 by ydegerli          #+#    #+#              #
#    Updated: 2023/03/08 13:41:01 by ydegerli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = functions.c lis_algorithm.c main.c move_to_a.c \
    transfer_to_b.c utils.c order.c stack_utils.c sort.c\
	ordertwo.c stack_functns.c stack_functns2.c operations_one.c \
	operations_two.c operations_three.c check_op_one.c check_op_two.c \
	check_op_three.c check_write.c get_next_line.c \
	get_next_line_utils.c border_ctl.c
SRC_BNS = functions.c lis_algorithm.c move_to_a.c \
    transfer_to_b.c utils.c order.c stack_utils.c sort.c\
	ordertwo.c stack_functns.c stack_functns2.c operations_one.c \
	operations_two.c operations_three.c check_op_one.c check_op_two.c \
	check_op_three.c check_write.c checker.c get_next_line.c \
	get_next_line_utils.c check_number.c border_ctl.c
OBJS = $(SRC:.c=.o)
OBJS_BNS = $(SRC_BNS:.c=.o)
NAME = push_swap
NAME_BNS = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror -I include
PRINTF = cd ft_printf && make
LIB1 = ft_printf/libftprintf.a
LIBFT = cd libft && make
LIB2 = libft/libft.a
all: ft_printf libft $(NAME)
bonus: ft_printf libft $(NAME_BNS)
libft:
				@$(LIBFT)
ft_printf:
				@$(PRINTF)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIB1) $(LIB2) -o $(NAME)
$(NAME_BNS): $(OBJS_BNS)
	$(CC) $(FLAGS) $(OBJS_BNS) $(LIB1) $(LIB2) -o $(NAME_BNS)
clean:
				$(RM) $(OBJS) $(OBJS_BNS)
				@cd libft && make clean
				@cd ft_printf && make clean
fclean:			clean
				$(RM) $(NAME) $(NAME_BNS)
				@cd ft_printf && make fclean
				@cd libft && make fclean
re:				fclean all
.PHONY:			all bonus libft ft_printf clean fclean re
