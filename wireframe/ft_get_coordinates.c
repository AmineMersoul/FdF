/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:07:29 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/13 21:11:51 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	ft_get_coordinates(const int x, const int y, void *param)
{
	t_edge		edge;
	int			first;
	int			second;
	static int	coordinates[2][250];
	static int	index;

	index = 0;
	coordinates[0][index] = x;
	coordinates[1][index] = y;
	if (index % 2 == 1)
	{
		first = index - 1;
		second = index;
		edge.vertex_1.x = coordinates[0][first];
		edge.vertex_1.y = coordinates[1][first];
		edge.vertex_2.x = coordinates[0][second];
		edge.vertex_2.y = coordinates[1][second];
		ft_draw_line(param, edge);
	}
	index++;
}
