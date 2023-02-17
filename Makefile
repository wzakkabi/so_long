NAME = a.a
FLAGS = -Wall -Wextra -Werror
SRC = so_long.c valid_path.c ./gg/get_next_line.c ./gg/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	mv get_next_line.o get_next_line_utils.o ./gg
	ar -rcs $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) -c $<

fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ)

re : fclean all