NAME = draw

SOURCE = *.c 
OFILES = *.o
INCLUDES = draw.h
LIB = draw.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SOURCE) $(INCLUDES)
	ar rc $(LIB) $(OFILES)
	ranlib $(LIB)

clean:
	rm -f $(OFILES)
	rm -f draw.h.gch

fclean: clean
	rm -f $(LIB)

re: fclean all