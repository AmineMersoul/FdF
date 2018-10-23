/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:45:33 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/23 12:16:03 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_edge	ft_offset_edge(t_edge edge, const t_vertex offset)
{
	edge.vertex_1.x += offset.x;
	edge.vertex_1.y += offset.y;
	edge.vertex_2.x += offset.x;
	edge.vertex_2.y += offset.y;
	return (edge);
}
