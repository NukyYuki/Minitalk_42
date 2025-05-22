CLIENT_SRC	= client.c
SERVER_SRC	= server.c
CFLAGS		= -Wextra -Werror -Wall
CC			= cc
RM			= rm -f
LIBFT_PATH	= libft
LIBFT_A		= ${LIBFT_PATH}/libft.a
CLIENT_NAME	= client
SERVER_NAME = server

all: ${CLIENT_NAME} ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_SRC} ${LIBFT_A}
	${CC} ${CFLAGS} ${CLIENT_SRC} ${LIBFT_A} -o $@

${SERVER_NAME}: ${SERVER_SRC} ${LIBFT_A}
	${CC} ${CFLAGS} ${SERVER_SRC} ${LIBFT_A} -o $@

${LIBFT_A}:
	${MAKE} -C ${LIBFT_PATH}

clean: 
	${MAKE} -C ${LIBFT_PATH} clean

fclean: clean
	${MAKE} -C ${LIBFT_PATH} fclean
	${RM} ${CLIENT_NAME} ${SERVER_NAME}

re: fclean all

.PHONY: all clean fclean re

