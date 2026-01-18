# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masselgu <masselgu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 17:30:11 by masselgu          #+#    #+#              #
#    Updated: 2026/01/18 13:33:47 by masselgu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC = push_swap.c check_input.c utils.c create_stack.c reverse_rotate_command.c  sort_three.c \
		sort_utils.c ft_split.c radix_sort.c rotate_command.c swap_command.c push_command.c
OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re