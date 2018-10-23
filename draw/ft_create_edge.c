/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:45:24 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/23 16:43:54 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_edge	ft_create_edge(t_vertex vertex_1, t_vertex vertex_2)
{
	t_edge edge;

	edge.vertex_1 = vertex_1;
	edge.vertex_2 = vertex_2;
	return (edge);
}
