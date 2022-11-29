# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axlamber <marvin@42.fr>                     +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 17:19:09 by axlamber           #+#    #+#             #
#    Updated: 2022/11/25 15:55:44 by axlamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = mandatory/ft_join.c mandatory/ft_split.c mandatory/main.c \
		mandatory/parsing.c mandatory/parsing_utils.c mandatory/map.c \
		mandatory/move.c mandatory/utils.c mandatory/utils2.c \
		mandatory/utils3.c

SRC_BONUS = bonus/ft_join.c bonus/ft_split.c bonus/main.c bonus/parsing.c \
		bonus/utils.c bonus/utils2.c bonus/utils3.c bonus/move.c bonus/map.c \
		bonus/enemy.c bonus/enemy_utils.c bonus/enemy_utils2.c \
		bonus/parsing_utils.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = ${SRC_BONUS:.c=.o}

PRINTF_A = libftprintf.a
PRINTF_DIR = printf/
PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

INCLUDE = includes/

.c.o :
	cc -Wall -Wextra -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	make -C $(PRINTF_DIR)
	cc ${OBJS} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${PRINTF} -o $(NAME)

bonus: $(OBJS_BONUS)
		make -C $(PRINTF_DIR)
		cc ${OBJS_BONUS} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${PRINTF} -o $(NAME)

clean:
	make clean -C printf
	rm -f $(OBJS) ${OBJS_BONUS}

fclean: clean
	make fclean -C printf
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
