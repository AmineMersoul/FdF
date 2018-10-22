/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_bresenham.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:28:19 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/22 19:49:18 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_case1(void *param, t_point point_1, int ex, t_line line_cal)
{
	int				i;
	int				c_dx;
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
	int				i;
	int				c_dy;
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

void		ft_draw_line_bresenham(void *param, t_line line)
{
	t_point	point_e;
	t_line	line_cal;

	point_e.x = ft_abs(line.point_2.x - line.point_1.x);
	point_e.y = ft_abs(line.point_2.y - line.point_1.y);
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
