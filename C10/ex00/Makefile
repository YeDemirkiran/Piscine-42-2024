NAME = ft_display_file

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./srcs/
SRCS = ${wildcard ${SRC}*.c}
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	${CC} $(CFLAGS) -o $@ $^

%.o: %.c
	${CC} $(CFLAGS) -c $< -o ${OBJ}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
