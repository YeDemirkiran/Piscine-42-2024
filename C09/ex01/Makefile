CC = cc
FLAGS = -c -Wall -Wextra -Werror -I

NAME = libft.a

SRC = ./srcs/
FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = ${addprefix ${SRC}, ${FILES}}

INCLUDE = ./includes
        
OBJ = ${SRCS:.c=.o}

all: ${NAME}
    
${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
	ranlib ${NAME}

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCLUDE) $< -o $@

clean:
	rm -f ${OBJ}
    
fclean: clean
	find . -name ${NAME} -delete
    
re: fclean all

.PHONY: all clean fclean re