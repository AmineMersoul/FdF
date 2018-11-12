#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../wireframe/wireframe.h"
#include <stdio.h>
#include <stdlib.h>

void	get_coordinates(const int x, const int y, void *param)
{
	static int 	coordinates[2][250];
	static int	index = 0;

	coordinates[0][index] = x;
	coordinates[1][index] = y;
	if (index % 2 == 1)
	{
		int first = index - 1;
		int second = index;
		// printing coordinates
		ft_putstr("x1 : ");
		ft_putnbr(coordinates[0][first]);
		ft_putstr(", y1 : ");
		ft_putnbr(coordinates[1][first]);
		ft_putstr(", x2 : ");
		ft_putnbr(coordinates[0][second]);
		ft_putstr(", y2 : ");
		ft_putnbr(coordinates[1][second]);
		ft_putstr("\n");
		
		t_edge edge;
		edge.vertex_1.x = coordinates[0][first];
		edge.vertex_1.y = coordinates[1][first];
		edge.vertex_2.x = coordinates[0][second];
		edge.vertex_2.y = coordinates[1][second];
		ft_draw_line(param, edge);
	}
	index++;
}

int	check_win_click(const int x, const int y)
{
	if (x < 0 || y < 0)
		return (0);
	return (1);
}


void	draw_surface_iso(t_surface *surface, void *param)
{
	int row;
	int col;
	t_edge projection;
	t_draw_params *params;

	params = (t_draw_params*)param;
	row = 0;
	while (row < surface->rows)
	{
		col = 0;
		while (col < surface->cols)
		{
			if (col + 1 < surface->cols)
			{
				
				projection = ft_create_edge(surface->vertex[row][col], surface->vertex[row][col + 1]);
				projection = ft_iso_projection(projection, params->extrude);
				projection = ft_scale_edge(projection , params->scale);
				projection = ft_offset_edge(projection, params->offset);
				ft_draw_line(param, projection);
			}
			if (row + 1 < surface->rows)
			{
				projection = ft_create_edge(surface->vertex[row][col], surface->vertex[row + 1][col]);
				projection = ft_iso_projection(projection, params->extrude);
				projection = ft_scale_edge(projection, params->scale);
				projection = ft_offset_edge(projection, params->offset);
				ft_draw_line(param, projection);
			}
			col++;
		}
		row++;
	}
}

void	draw_surface_top(t_surface *surface, const int scale, void *param)
{
	int row;
	int col;
	t_vertex offset;
	t_edge edge;

	offset.x = 100;
	offset.y = 50;
	row = 0;
	while (row < surface->rows)
	{
		col = 0;
		while (col < surface->cols)
		{
			if (col + 1 < surface->cols)
			{
				edge = ft_create_edge(surface->vertex[row][col], surface->vertex[row][col + 1]);
				edge = ft_scale_edge(edge , scale);
				edge = ft_offset_edge(edge, offset);
				ft_draw_line(param, edge);
			}
			if (row + 1 < surface->rows)
			{
				edge = ft_create_edge(surface->vertex[row][col], surface->vertex[row + 1][col]);
				edge = ft_scale_edge(edge, scale);
				edge = ft_offset_edge(edge, offset);
				ft_draw_line(param, edge);
			}
			col++;
		}
		row++;
	}
}

void	draw_help(void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	if (params->help == 0)
		return ;
	mlx_string_put(params->mlx_ptr, params->win_ptr, 32, 32, 0xFFFFFF, "presse 'esc' key to exit");
	mlx_string_put(params->mlx_ptr, params->win_ptr, 32, 64, 0xFFFFFF, "presse 'c' key to clear screen");
	mlx_string_put(params->mlx_ptr, params->win_ptr, 400, 32, 0xFFFFFF, "presse key 'up' or 'down' to change height");
	mlx_string_put(params->mlx_ptr, params->win_ptr, 400, 64, 0xFFFFFF, "click on the screen to draw lignes");
}

void	redraw(void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	draw_help(param);
	draw_surface_iso(params->surface, param);
}

//	event method for keyboard
int	deal_key(int key, void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;

	// if esc pressed then exit
	if (key == 53)
		exit(0);
	// clear screen if c pressed
	if (key == 8)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		draw_help(param);
	}
	// key up pressed
	if (key == 126)
	{
		params->extrude += 0.02;
		redraw(params);
	}
	// key down pressed
	if (key == 125)
	{
		params->extrude -= 0.02;
		redraw(params);
	}
	// key '-' pressed
	if (key == 78)
	{
		if (params->scale > 0.5)
			params->scale -= 0.5;
		redraw(params);
	}
	// key '+' pressed
	if (key == 69)
	{
		params->scale += 0.5;
		redraw(params);
	}
	// key w pressed
	if (key == 13)
	{
		params->offset.y -= 50;
		redraw(params);
	}
	// key s pressed
	if (key == 1)
	{
		params->offset.y += 50;
		redraw(params);
	}
	// key d pressed
	if (key == 2)
	{
		params->offset.x += 50;
		redraw(params);
	}
	// key a pressed
	if (key == 0)
	{
		params->offset.x -= 50;
		redraw(params);
	}
	// key r pressed
	if (key == 15)
	{
		params->color.r -= 10;
		redraw(params);
	}
	// key g pressed
	if (key == 5)
	{
		params->color.g -= 10;
		redraw(params);
	}
	// key b pressed
	if (key == 11)
	{
		params->color.b -= 10;
		redraw(params);
	}
	if (key == 122)
	{
		if (params->help == 0)
			params->help = 1;
		else
			params->help = 0;
		redraw(params);
	}
	// printing key pressed
	ft_putstr("key : ");
	ft_putnbr(key);
	ft_putstr(", \n");
	return (0);
}

//	event method for mouse
int	deal_key_mouse(int button, int x, int y, void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;

	if (button == 1 && check_win_click(x, y))
		get_coordinates(x, y, param);

	if (button == 5)
	{
		if (params->scale > 0.5)
			params->scale -= 0.5;
		redraw(params);
	}
	// key '+' pressed
	if (button == 4)
	{
		params->scale += 0.5;
		redraw(params);
	}
	// printing key button
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putstr("\n");
	return (0);
}

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

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char *file_path = "maps/mars.fdf";

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
	ft_count_x_y(fd, &x, &y);
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
	params->color = ft_create_color(255, 255, 255);
	params->extrude = 0.2f;
	params->scale = 1900 / 2 / (x + y);
	params->surface = surface;
	params->offset = ft_create_vertex(710, 100, 0);

	// draw string on screen
	draw_help(params);

	// drawing surface
	draw_surface_iso(surface, params);

	// event hooker for window
	mlx_key_hook(win_ptr, deal_key, params);
	mlx_mouse_hook(win_ptr, deal_key_mouse, params);
	mlx_loop(mlx_ptr);
	return 0;
}
