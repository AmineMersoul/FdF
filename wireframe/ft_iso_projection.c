/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:41:33 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/24 11:17:49 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

t_edge		ft_iso_projection(t_edge edge, float extrude)
{
	t_edge screen;

	screen.vertex_1.x = (edge.vertex_1.x - edge.vertex_1.y) * 2;
	screen.vertex_1.y = (edge.vertex_1.x + edge.vertex_1.y -
						(edge.vertex_1.z * extrude)) * 1;
	screen.vertex_2.x = (edge.vertex_2.x - edge.vertex_2.y) * 2;
	screen.vertex_2.y = (edge.vertex_2.x + edge.vertex_2.y -
						(edge.vertex_2.z * extrude)) * 1;
	return (screen);
}
