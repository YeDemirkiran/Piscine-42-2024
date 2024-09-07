NAME = ft_cat

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./srcs/
SRCS = ${wildcard ${SRC}*.c}
OBJ = $(SRCS:.c=.o)
INC_DIR = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	${CC} $(CFLAGS) -I ${INC_DIR} -o $@ $^

%.o: %.c
	${CC} $(CFLAGS) -I ${INC_DIR} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
