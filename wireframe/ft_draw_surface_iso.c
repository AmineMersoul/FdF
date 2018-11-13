/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_surface_iso.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:08:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/13 19:42:18 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

static void	draw_ligne_h(t_surface *surface, void *param, int col, int row)
{
	t_edge			projection;
	t_draw_params	*params;

	params = (t_draw_params*)param;
	projection = ft_create_edge(surface->vertex[row][col],
	surface->vertex[row][col + 1]);
	if (params->colorize)
		ft_altitude_colors(param, projection.vertex_1, projection.vertex_2);
	if (params->view)
		projection = ft_iso_projection(projection, params->extrude);
	projection = ft_scale_edge(projection, params->scale);
	projection = ft_offset_edge(projection, params->offset);
	ft_draw_line(param, projection);
}

static void	draw_ligne_v(t_surface *surface, void *param, int col, int row)
{
	t_edge			projection;
	t_draw_params	*params;

	params = (t_draw_params*)param;
	projection = ft_create_edge(surface->vertex[row][col],
	surface->vertex[row + 1][col]);
	if (params->colorize)
		ft_altitude_colors(param, projection.vertex_1, projection.vertex_2);
	if (params->view)
		projection = ft_iso_projection(projection, params->extrude);
	projection = ft_scale_edge(projection, params->scale);
	projection = ft_offset_edge(projection, params->offset);
	ft_draw_line(param, projection);
}

void		ft_draw_surface_iso(t_surface *surface, void *param)
{
	int				row;
	int				col;

	row = 0;
	while (row < surface->rows)
	{
		col = 0;
		while (col < surface->cols)
		{
			if (col + 1 < surface->cols)
			{
				draw_ligne_h(surface, param, col, row);
			}
			if (row + 1 < surface->rows)
			{
				draw_ligne_v(surface, param, col, row);
			}
			col++;
		}
		row++;
	}
}
