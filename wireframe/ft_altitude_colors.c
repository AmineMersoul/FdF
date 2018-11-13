/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altitude_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:22:09 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/13 19:26:35 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	ft_altitude_colors(void *param, t_vertex vertex_1, t_vertex vertex_2)
{
	t_draw_params	*params;

	params = (t_draw_params*)param;
	if (vertex_1.z > 0 && vertex_2.z > 0)
		params->color = ft_create_color(255, 255, 255);
	else if (vertex_1.z > 0 || vertex_2.z > 0)
		params->color = ft_create_color(244, 149, 66);
	else
		params->color = ft_create_color(113, 244, 66);
}
