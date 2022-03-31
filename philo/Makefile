# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 16:56:53 by merlich           #+#    #+#              #
#    Updated: 2022/03/31 22:29:37 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	main.c threads.c mutexes.c ft_live.c time.c ft_atoi.c

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
