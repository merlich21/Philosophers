# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 16:56:53 by merlich           #+#    #+#              #
#    Updated: 2022/04/06 22:44:15 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	main_bonus.c ft_check_input_bonus.c ft_live_bonus.c \
			time_bonus.c ft_atoi_bonus.c child_bonus.c \
			init_bonus.c monitoring_bonus.c threads_bonus.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	philo_bonus.h

CFLAGS	=	-Wall -Wextra -Werror -I ${HEADER}

%.o:	%.c
		${CC} ${CFLAGS} -c $< -o $@

.PHONY:	all clean fclean re

all:	${NAME}

${NAME}:	${HEADER} ${OBJS}
			${CC} ${OBJS} -o ${NAME}

clean:	
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all
