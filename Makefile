NAME = fdf

SOURCE = main.c 

MINILIBX = minilibx/
LIBS = libft/libft.a wireframe/wireframe.a util/util.a get_next_line/get_next_line.c
FLAGS = -lmlx -framework OpenGl -framework AppKit

run:
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

all: $(NAME)

mlibft:
	cd libft && $(MAKE) re && $(MAKE) clean

mutil:
	cd util && $(MAKE) re && $(MAKE) clean

mwireframe:
	cd wireframe && $(MAKE) re && $(MAKE) clean

$(NAME): mwireframe mlibft mutil
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

clean:
	cd libft && $(MAKE) clean
	cd util && $(MAKE) clean
	cd wireframe && $(MAKE) clean

fclean: clean
	cd libft && $(MAKE) fclean
	cd util && $(MAKE) fclean
	cd wireframe && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all