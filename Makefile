NAME = fdf

SOURCE = main.c 

MINILIBX = minilibx/
LIBS = libft/libft.a wireframe/wireframe.a get_next_line/get_next_line.c
FLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

run:
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

mlibft:
	cd libft && $(MAKE) re && $(MAKE) clean

mwireframe:
	cd wireframe && $(MAKE) re && $(MAKE) clean

$(NAME): mwireframe mlibft
	cc -I $(MINILIBX) $(SOURCE) $(LIBS) -L $(MINILIBX) $(FLAGS) -o $(NAME)

clean:
	cd libft && $(MAKE) clean
	cd wireframe && $(MAKE) clean

fclean: clean
	cd libft && $(MAKE) fclean
	cd wireframe && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all