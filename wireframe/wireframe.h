/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:18:52 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/24 15:37:18 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WIREFRAME_H
# define __WIREFRAME_H

# include "../minilibx/mlx.h"
# include "../util/util.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct
{
	float		x;
	float		y;
	float		z;
}				t_vertex;

typedef struct
{
	t_vertex	vertex_1;
	t_vertex	vertex_2;
}	t_edge;

typedef struct
{
	t_vertex	**vertex;
	int			rows;
	int			cols;
}	t_surface;

typedef struct
{
	int			color;
	float		scale;
	float		extrude;
	void		*mlx_ptr;
	void		*win_ptr;
	t_surface	*surface;
	t_vertex	offset;
}				t_draw_params;

t_vertex		ft_create_vertex(const int x, const int y, const int z);
t_edge			ft_create_edge(t_vertex vertex_1, t_vertex vertex_2);
void			ft_draw_line(void *param, t_edge edge);
t_edge			ft_offset_edge(t_edge edge, const t_vertex offset);
t_edge			ft_scale_edge(t_edge edge, const float scale);
t_edge			ft_iso_projection(t_edge edge, float extrude);
void			ft_count_x_y(const int fd, int *x, int *y);
t_surface		*ft_create_surface(const int fd, const int x, const int y);

#endif
