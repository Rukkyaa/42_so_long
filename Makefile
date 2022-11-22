# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axlamber <marvin@42.fr>                     +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 17:19:09 by axlamber           #+#    #+#             #
#    Updated: 2022/11/22 11:35:25 by axlamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ft_join.c ft_split.c main.c parsing.c utils.c utils2.c move.c map.c

OBJS = ${SRC:.c=.o}

INCLUDE = includes/

.c.o :
	cc -Wall -Wextra -g -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	cc ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux\
		-lXext -lX11 -lm -lz -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
