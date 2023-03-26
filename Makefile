# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 20:13:59 by agil-ord          #+#    #+#              #
#    Updated: 2023/03/23 17:36:14 by agil-ord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ITS IS MAKEFILE PUSH_SWAP

INCLUDE = -I ./libft/includes -I ./includes
 
NAME	=	push_swap

DIR_PUSH_SWAP = ./src

SRC_PUSH_SWAP =	push_swap.c

SRCS		=	${addprefix ${DIR_PUSH_SWAP}/,${SRC_PUSH_SWAP}}

#OBJS		=	${addprefix ${DIR_PUSH_SWAP}/,${SRC_PUSH_SWAP:.c=.o}}

LIBFT_DIR	=	./libft

AR			=	ar	-crs ${INCLUDE}

CC			=	gcc

CFLAG		=	-Wall -Werror -Wextra ${INCLUDE}

RM			=	rm -f

all: ${NAME}

${NAME}: 
		@make -C ${LIBFT_DIR}
#		@cp ${LIBFT_DIR}/libft.a ${NAME}
		${CC} ${CFLAG} ${SRCS} ${LIBFT_DIR}/libft.a -o ${NAME}

clean:	
		@make clean -C ${LIBFT_DIR} 
		${RM} ${NAME}

fclean:	clean
		@make fclean -C ${LIBFT_DIR} 
		${RM} ${NAME} 
		
re:	fclean all
