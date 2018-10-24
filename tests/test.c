void	draw_surface_front(int **surface, const int x, const int y, const int s, void *param)
{
	int c;
	int r;
	t_point offset;

	offset.x = 100;
	offset.y = 100;
	r = 0;
	ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(0, 0, x, 0), s), offset));
	while (r < y)
	{
		c = 0;
		while (c < x)
		{
			if (surface[r][c] != 0)
			{
				ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(c, 0, c, surface[r][c]), s), offset));
				if (surface[r][c + 1] > 0)
					ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(c, surface[r][c], (c + 1), surface[r][c]), s), offset));
				//ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(c, r, (c + 1), r), s), offset));
			}
			c++;
		}
		r++;
	}
}

void	draw_surface_side(int **surface, const int x, const int y, const int s, void *param)
{
	int c;
	int r;
	t_point offset;

	offset.x = 100;
	offset.y = 100;
	r = 0;
	ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(0, 1, y, 1), s), offset));
	while (r < y)
	{
		c = 0;
		while (c < x)
		{
			if (surface[r][c] > 0)
			{
				ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(r, 0, r, 1), s), offset));
				if (surface[r + 1][c] > 0)
					ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(r, 0, (r + 1), 0), s), offset));
				ft_draw_line_bresenham(param, ft_offset_line(ft_scale_line(ft_create_line(r, c, r, (c + 1)), s), offset));
			}
			c++;
		}
		r++;
	}
}