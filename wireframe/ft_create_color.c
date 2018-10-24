/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:00:23 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/24 20:00:35 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

t_color	ft_create_color(const int r, const int g, const int b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
