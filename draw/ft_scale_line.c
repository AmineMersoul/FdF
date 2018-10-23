/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:46:48 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/23 12:16:25 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_edge	ft_scale_edge(t_edge edge, const int scale)
{
	edge.vertex_1.x *= scale;
	edge.vertex_1.y *= scale;
	edge.vertex_2.x *= scale;
	edge.vertex_2.y *= scale;
	return (edge);
}
