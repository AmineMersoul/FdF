#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../draw/draw.h"
#include <stdlib.h>

static void	draw_case1(void *param, t_point point_1, int ex, t_line line_cal)
{
	int			i;
	int			c_dx;
	t_draw_params	*params;

	params = (t_draw_params*)param;
	i = 0;
	c_dx = ex;
	while (i <= c_dx)
	{
		mlx_pixel_put(params->mlx_ptr, params->win_ptr,
		point_1.x, point_1.y, params->color);
		i++;
		point_1.x += line_cal.point_2.x;
		ex -= line_cal.point_1.y;
		if (ex < 0)
		{
			point_1.y += line_cal.point_2.y;
			ex += line_cal.point_1.x;
		}
	}
}

static void	draw_case2(void *param, t_point point_1, int ey, t_line line_cal)
{
	int			i;
	int			c_dy;
	t_draw_params	*params;

	params = (t_draw_params*)param;
	i = 0;
	c_dy = ey;
	while (i <= c_dy)
	{
		mlx_pixel_put(params->mlx_ptr, params->win_ptr,
		point_1.x, point_1.y, params->color);
		i++;
		point_1.y += line_cal.point_2.y;
		ey -= line_cal.point_1.x;
		if (ey < 0)
		{
			point_1.x += line_cal.point_2.x;
			ey += line_cal.point_1.y;
		}
	}
}

void		draw_line_bresenham(void *param, t_line line)
{
	t_point	point_e;
	t_line	line_cal;

	point_e.x = abs(line.point_2.x - line.point_1.x);
	point_e.y = abs(line.point_2.y - line.point_1.y);
	line_cal.point_1.x = 2 * point_e.x;
	line_cal.point_1.y = 2 * point_e.y;
	line_cal.point_2.x = 1;
	line_cal.point_2.y = 1;
	if (line.point_1.x > line.point_2.x)
		line_cal.point_2.x = -1;
	if (line.point_1.y > line.point_2.y)
		line_cal.point_2.y = -1;
	if (point_e.x > point_e.y)
		draw_case1(param, line.point_1, point_e.x, line_cal);
	else
		draw_case2(param, line.point_1, point_e.y, line_cal);
}



void	get_coordinates(int x, int y, void *param)
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
		ft_putstr(" ");
		
		t_line line;
		line.point_1.x = coordinates[0][first];
		line.point_1.y = coordinates[1][first];
		line.point_2.x = coordinates[0][second];
		line.point_2.y = coordinates[1][second];
		draw_line_bresenham(param, line);
	}
	index++;
}

//	event method for the window
int	deal_key(int key, void *param)
{
	// if esc pressed then exit
	if (key == 53)
		exit(0);
	// printing key pressed
	ft_putstr("key : ");
	ft_putnbr(key);
	ft_putstr(", ");
	return (0);
}

int	deal_key_mouse(int button, int x, int y, void *param)
{
	// printing key button
	get_coordinates(x, y, param);
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putstr(", ");
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	// init and create new mlx window
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 800, "mlx test");
	t_draw_params *params = malloc(sizeof(t_draw_params));
	
	params->win_ptr = win_ptr;
	params->mlx_ptr = mlx_ptr;
	params->color = 0xFFFFFF;

	// event hooker for window
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, deal_key_mouse, params);

	mlx_loop(mlx_ptr);
	return 0;
}
