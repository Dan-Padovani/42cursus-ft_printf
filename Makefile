# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 18:34:11 by dpadovan          #+#    #+#              #
#    Updated: 2021/07/31 18:48:23 by dpadovan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

MYLIB		=	ft_printf.h

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

OBJS		=	${SRCS:.c=.o}

LIB			=	ar -rcs

RM			=	rm -f

SRCS		=	${FILES}

FILES		=	ft_printf.c ft_print_char.c ft_print_integer.c \
				ft_print_string.c ft_print_unsigned_int.c ft_print_hex.c \
				ft_print_pointer.c ft_print_utils.c\

all:		${NAME}

${NAME}:	${OBJS} ${MYLIB}
			${LIB} ${NAME} ${OBJS}

.c.o:
			${CC} ${CFLAGS} -c $< -o $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re