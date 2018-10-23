/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:18:52 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/23 19:35:17 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DRAW_H
# define __DRAW_H

# include "../minilibx/mlx.h"
# include "../util/util.h"

typedef struct
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
}				t_draw_params;

typedef struct
{
	float			x;
	float			y;
	float			z;
}				t_vertex;

typedef struct
{
	t_vertex		vertex_1;
	t_vertex		vertex_2;
}	t_edge;

t_vertex	ft_create_vertex(const int x, const int y, const int z);
t_edge		ft_create_edge(t_vertex vertex_1, t_vertex vertex_2);
void		ft_draw_line(void *param, t_edge edge);
t_edge		ft_offset_edge(t_edge edge, const t_vertex offset);
t_edge		ft_scale_edge(t_edge edge, const int scale);
#endif
