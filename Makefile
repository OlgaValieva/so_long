# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carys <carys@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 16:51:29 by carys             #+#    #+#              #
#    Updated: 2022/02/24 11:33:48 by carys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

HEADER	=	so_long.h

SRCS_S	=	ft_check_map.c ft_check_char.c gnl.c utils.c

SRCS_A	=	main.c ft_key_hook.c

SRCS_BONUS	=	main_bonus.c animation_bonus.c enemy_bonus.c ft_itoa_bonus.c ft_key_hook_bonus.c

OBJS_S	=	${SRCS_S:%.c=%.o}

OBJS_A	=	${SRCS_A:%.c=%.o}

OBJS_BONUS	=	${SRCS_BONUS:%.c=%.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

MLX_FLAGS =	-lmlx -framework OpenGL -framework AppKit

.PHONY:		all clean fclean re bonus

all:		${NAME}

%.o: 		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS_A} ${OBJS_S} ${HEADER}
			${CC} ${CFLAGS} ${MLX_FLAGS} -o ${NAME} ${OBJS_A} ${OBJS_S}

bonus:
			@make OBJS_A="$(OBJS_BONUS)" all

clean:
			${RM} ${OBJS_A} ${OBJS_BONUS} ${OBJS_S}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
