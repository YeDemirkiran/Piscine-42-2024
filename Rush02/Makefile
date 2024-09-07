NAME = rush-02

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ./src
SRCS = $(wildcard $(SRC)/*.c)
HEAD = ./includes
OBJ = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${FLAGS} -I ${HEAD} -o ${NAME} ${OBJ}

%.o : %.c
	${CC} -c ${FLAGS} -I ${HEAD} $< -o ${<:.c=.o}

${OBJ}: ${SRCS}

clean:
	rm -f ${OBJ}

fclean: clean	
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re