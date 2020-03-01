NAME = bsq
SOURCE = *.c
OBJECTS = *.o
HEADER = rushheader.h
FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	gcc $(FLAGS) $(SOURCE)
	gcc *.o -o $(NAME)
clean:
	/bin/rm -f $(OBJECTS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
