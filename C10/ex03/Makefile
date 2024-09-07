NAME = ft_hexdump

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
INC_DIR = ./includes
SRCS = $(wildcard ${SRC_DIR}*.c)
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INC_DIR) $^ -o $@
 
%.o:%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re