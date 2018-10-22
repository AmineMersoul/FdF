NAME = util

SOURCE = *.c 
OFILES = *.o
INCLUDES = util.h
LIB = util.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SOURCE) $(INCLUDES)
	ar rc $(LIB) $(OFILES)
	ranlib $(LIB)

clean:
	rm -f $(OFILES)
	rm -f util.h.gch

fclean: clean
	rm -f $(LIB)

re: fclean all