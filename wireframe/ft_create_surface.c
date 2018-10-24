/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:48:10 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/24 11:33:17 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

static void		surface_init(t_surface **surface, const int x, const int y)
{
	int i;

	*surface = malloc(sizeof(*surface));
	(*surface)->rows = y;
	(*surface)->cols = x;
	(*surface)->vertex = (t_vertex **)malloc(sizeof(t_vertex *) * y);
	(*surface)->vertex[0] = (t_vertex *)malloc(sizeof(t_vertex) * y * x);
	i = 0;
	while (++i < y)
		(*surface)->vertex[i] = (*(*surface)->vertex + x * i);
}

t_surface		*ft_create_surface(const int fd, const int x, const int y)
{
	char		*line;
	int			row;
	int			col;
	char		**res;
	t_surface	*surface;

	surface_init(&surface, x, y);
	row = 0;
	while (get_next_line(fd, &line))
	{
		res = ft_strsplit((const char*)line, ' ');
		col = 0;
		while (res[col] != 0)
		{
			surface->vertex[row][col] =
				ft_create_vertex(col, row, ft_atoi((const char *)res[col]));
			col++;
		}
		row++;
	}
	return (surface);
}
