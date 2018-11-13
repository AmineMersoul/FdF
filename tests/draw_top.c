#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../wireframe/wireframe.h"
#include <stdio.h>
#include <stdlib.h>

void	print_surface(t_surface *surface)
{
	int row;
	int col;

	row = 0;
	while (row < surface->rows)
	{
		col = 0;
		while (col < surface->cols)
		{
			printf("row=%.6f, col=%.6f, val=%.6f\n", surface->vertex[row][col].x, surface->vertex[row][col].y, surface->vertex[row][col].z);
			col++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		void	*mlx_ptr;
		void	*win_ptr;
		char *file_path = argv[1];

		int x, y;
		t_surface *surface;

		// open file
		int fd = open((char *)file_path, O_RDONLY);
		if (fd < 2)
		{
			printf("can't open the map file");
			return (-1);
		}

		// counting x and y
		if (!ft_count_x_y(fd, &x, &y))
		{
			printf("Found wrong line length. Exiting.\n");
			return (0);
		}
		close(fd);

		// creating wireframe
		fd = open((char *)file_path, O_RDONLY);
		surface = ft_create_surface(fd, x, y);
		close(fd);

		//printf("rows = %d, cols = %d\n", surface->rows, surface->cols);
		//print_surface(surface);

		// init and create new mlx window
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "mlx test");

		t_draw_params *params = malloc(sizeof(t_draw_params));
		params->win_ptr = win_ptr;
		params->mlx_ptr = mlx_ptr;
		params->help = 0;
		params->view = 1;
		params->colorize = 0;
		params->color = ft_create_color(255, 255, 255);
		params->extrude = 0.3f;
		params->scale = 1900 / 2 / (x + y);
		params->surface = surface;
		params->offset = ft_create_vertex(710, 100, 0);

		// draw string on screen
		ft_draw_help(params);

		// drawing surface
		ft_draw_surface_iso(surface, params);

		// event hooker for window
		mlx_key_hook(win_ptr, ft_deal_key, params);
		mlx_mouse_hook(win_ptr, ft_deal_mouse, params);
		mlx_loop(mlx_ptr);
	}
	else
		ft_putstr("Usage : ./fdf <filename>\n");
	return 0;
}
