/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:46:16 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/14 11:55:15 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void			ft_print_surface(t_surface *surface)
{
	int row;
	int col;

	row = 0;
	while (row < surface->rows)
	{
		col = 0;
		while (col < surface->cols)
		{
			ft_putstr("row = ");
			ft_putnbr(surface->vertex[row][col].x);
			ft_putstr(", col = ");
			ft_putnbr(surface->vertex[row][col].y);
			ft_putstr(", val = ");
			ft_putnbr(surface->vertex[row][col].z);
			ft_putstr("\n");
			col++;
		}
		row++;
	}
}
