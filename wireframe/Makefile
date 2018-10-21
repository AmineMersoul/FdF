NAME = wireframe

SOURCE = *.c 
OFILES = *.o
INCLUDES = wireframe.h
LIB = wireframe.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SOURCE) $(INCLUDES)
	ar rc $(LIB) $(OFILES)
	ranlib $(LIB)

clean:
	rm -f $(OFILES)
	rm -f wireframe.h.gch

fclean: clean
	rm -f $(LIB)

re: fclean all