/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:28:19 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/23 12:20:08 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_case1(void *param, t_vertex vertex_1, int ex, t_edge edge_cal)
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
		vertex_1.x, vertex_1.y, params->color);
		i++;
		vertex_1.x += edge_cal.vertex_2.x;
		ex -= edge_cal.vertex_1.y;
		if (ex < 0)
		{
			vertex_1.y += edge_cal.vertex_2.y;
			ex += edge_cal.vertex_1.x;
		}
	}
}

static void	draw_case2(void *param, t_vertex vertex_1, int ey, t_edge edge_cal)
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
		vertex_1.x, vertex_1.y, params->color);
		i++;
		vertex_1.y += edge_cal.vertex_2.y;
		ey -= edge_cal.vertex_1.x;
		if (ey < 0)
		{
			vertex_1.x += edge_cal.vertex_2.x;
			ey += edge_cal.vertex_1.y;
		}
	}
}

void		ft_draw_line(void *param, t_edge edge)
{
	t_vertex	vertex_e;
	t_edge	edge_cal;

	vertex_e.x = ft_abs(edge.vertex_2.x - edge.vertex_1.x);
	vertex_e.y = ft_abs(edge.vertex_2.y - edge.vertex_1.y);
	edge_cal.vertex_1.x = 2 * vertex_e.x;
	edge_cal.vertex_1.y = 2 * vertex_e.y;
	edge_cal.vertex_2.x = 1;
	edge_cal.vertex_2.y = 1;
	if (edge.vertex_1.x > edge.vertex_2.x)
		edge_cal.vertex_2.x = -1;
	if (edge.vertex_1.y > edge.vertex_2.y)
		edge_cal.vertex_2.y = -1;
	if (vertex_e.x > vertex_e.y)
		draw_case1(param, edge.vertex_1, vertex_e.x, edge_cal);
	else
		draw_case2(param, edge.vertex_1, vertex_e.y, edge_cal);
}
