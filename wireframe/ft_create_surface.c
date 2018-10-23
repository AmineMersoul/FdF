/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:48:10 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/23 19:00:27 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

t_surface		*ft_create_surface(const int fd, const int x, const int y)
{
	char	*line;
	int		row;
	int		col;
	char	**res;
	t_surface *surface;

	surface = malloc(sizeof(surface));
	surface->rows = y;
	surface->cols = x;
	surface->t_vertex  = (t_vertex **)malloc(sizeof(t_vertex *) * y); 
    surface->t_vertex[0] = (t_vertex *)malloc(sizeof(t_vertex) * y * x); 
    for(row = 0; row < y; row++) 
        surface->t_vertex[row] = (*surface->t_vertex + x * row);
	row = 0;
	while (get_next_line(fd, &line))
	{
		res = ft_strsplit((const char*)line, ' ');
		col = 0;
		while (res[col] != 0)
		{
			surface->t_vertex[row][col] = ft_create_vertex(row, col, ft_atoi((const char *)res[col]));
			col++;
		}
		row++;
	}
	return (surface);
}
