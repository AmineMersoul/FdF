#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../wireframe/wireframe.h"
#include <stdio.h>
#include <stdlib.h>

t_surface		*read_file(char *file_path, int *x, int *y)
{
	int			fd;
	t_surface	*surface;

	surface = malloc(sizeof(t_surface));
	fd = open(file_path, O_RDONLY);
	if (fd < 2)
	{
		ft_putstr("can't open the map file");
		return (NULL);
	}
	if (!ft_count_x_y(fd, x, y))
	{
		ft_putstr("Found wrong line length. Exiting.\n");
		return (NULL);
	}
	close(fd);
	fd = open(file_path, O_RDONLY);
	surface = ft_create_surface(fd, *x, *y);
	close(fd);
	return (surface);
}

t_draw_params	*setup_params(int xy, int argc, char **argv)
{
	t_draw_params *params;

	params = malloc(sizeof(t_draw_params));
	params->help = 0;
	params->view = 1;
	params->colorize = 0;
	params->color = ft_create_color(255, 255, 255);
	if (argc == 4)
	{
		params->extrude = ft_atoi(argv[3]) * 0.1;
		params->scale = ft_atoi(argv[2]);
	}
	else
	{
		params->extrude = 0.3f;
		params->scale = 1900 / 2 / (xy);
	}
	params->offset = ft_create_vertex(650, 100, 0);
	return (params);
}

void			create_window(t_surface *surface, int xy, int argc, char **argv)
{
	t_draw_params	*params;
	void			*mlx_ptr;
	void			*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "mlx test");
	params = setup_params(xy, argc, argv);
	params->win_ptr = win_ptr;
	params->mlx_ptr = mlx_ptr;
	params->surface = surface;
	ft_draw_help(params);
	ft_draw_surface_iso(surface, params);
	mlx_key_hook(win_ptr, ft_deal_key, params);
	mlx_mouse_hook(win_ptr, ft_deal_mouse, params);
	mlx_loop(mlx_ptr);
}

int				main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	t_surface	*surface;

	if (argc == 2 || argc == 4)
	{
		surface = read_file(argv[1], &x, &y);
		if (surface == NULL)
			return (0);
		create_window(surface, x + y, argc, argv);
	}
	else
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
	return (0);
}
