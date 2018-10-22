/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:45:33 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/22 19:48:40 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_line	ft_offset_line(t_line line, const t_point offset)
{
	line.point_1.x += offset.x;
	line.point_1.y += offset.y;
	line.point_2.x += offset.x;
	line.point_2.y += offset.y;
	return (line);
}
