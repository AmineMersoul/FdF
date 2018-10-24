/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:12:19 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/24 11:18:22 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

t_vertex	ft_create_vertex(const int x, const int y, const int z)
{
	t_vertex vertex;

	vertex.x = x;
	vertex.y = y;
	vertex.z = z;
	return (vertex);
}
