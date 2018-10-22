/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:46:48 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/22 19:49:00 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_line	ft_scale_line(t_line line, const int scale)
{
	line.point_1.x *= scale;
	line.point_1.y *= scale;
	line.point_2.x *= scale;
	line.point_2.y *= scale;
	return (line);
}
