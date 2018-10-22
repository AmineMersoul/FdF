/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:45:24 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/22 15:46:29 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_line	create_line(const int x1, const int y1, const int x2, const int y2)
{
	t_line line;

	line.point_1.x = x1;
	line.point_1.y = y1;
	line.point_2.x = x2;
	line.point_2.y = y2;
	return (line);
}
