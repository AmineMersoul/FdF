NAME = libft

SOURCE = *.c 
OFILES = *.o
INCLUDES = libft.h
LIB = libft.a

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SOURCE) $(INCLUDES)
	ar rc $(LIB) $(OFILES)
	ranlib $(LIB)

clean:
	rm -f $(OFILES)
	rm -f libft.h.gch

fclean: clean
	rm -f $(LIB)

re: fclean all