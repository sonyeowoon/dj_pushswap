# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djang <djang@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 01:47:05 by djang             #+#    #+#              #
#    Updated: 2024/06/18 01:47:08 by djang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS = checker

SRCS = ./atob_util.c ./atob.c ./btoa_util.c ./btoa.c\
 ./check_util.c ./check_util2.c ./deque_util.c ./deque_util2.c ./ft_atoi.c\
 ./minmax.c ./operator_greedy.c ./operator.c ./operator2.c ./operator3.c\
 ./sort_indexing.c ./push_swap.c

BONUS_SRCS = ./bonus/check_util_bonus.c ./bonus/check_util_bonus2.c\
 ./bonus/checker_bonus.c ./bonus/deque_util_bonus.c\
 ./bonus/deque_util2_bonus.c ./bonus/ft_atoi_bonus.c\
 ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c\
 ./bonus/operator_bonus.c ./bonus/operator2_bonus.c ./bonus/operator3_bonus.c\
 ./bonus/push_swap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

#%.o : %.c
#	$(CC) $(CCFLAGS) -c $^

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all

bonus : $(BONUS)
$(BONUS) : $(BONUS_OBJS)
	$(CC) $(CCFLAGS) $(BONUS_OBJS) -o $(BONUS)

.PHONY : all clean fclean re bonus