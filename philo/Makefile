# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 16:56:53 by merlich           #+#    #+#              #
#    Updated: 2022/04/06 20:59:39 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	main.c ft_check_input.c threads.c mutexes.c \
			ft_live.c time.c ft_atoi.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	philo.h

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
