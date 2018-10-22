/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:18:52 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/22 19:49:06 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DRAW_H
# define __DRAW_H

# include "../minilibx/mlx.h"
# include "../util/util.h"

typedef struct	s_draw_param
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
}				t_draw_params;

typedef struct
{
	int			x;
	int			y;
}				t_point;

typedef struct
{
	t_point		point_1;
	t_point		point_2;
}	t_line;

void			ft_draw_line_bresenham(void *param, t_line line);
t_line			ft_create_line(const int x1, const int y1,
const int x2, const int y2);
t_line			ft_offset_line(t_line line, const t_point offset);
t_line			ft_scale_line(t_line line, const int scale);

#endif
