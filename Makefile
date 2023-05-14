NAME = so_long
FLAGS = -Wall -Wextra -Werror
SRC = so_long.c valid_path.c get_next_line.c get_next_line_utils.c chyatasolong.c main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs so_long.a $(OBJ)
	gcc $(FLAGS) main.c so_long.a libmlx.dylib -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $<

fclean : clean
	rm -rf so_long.a $(NAME)

clean :
	rm -rf $(OBJ)

re : fclean all