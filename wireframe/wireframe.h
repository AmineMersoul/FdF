/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 14:51:02 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/23 18:02:30 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WIREFRAME_H
# define __WIREFRAME_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../draw/draw.h"

typedef struct
{
	t_vertex	**t_vertex;
	int			rows;
	int			cols;
}				t_surface;

void			ft_count_x_y(const int fd, int *x, int *y);
t_surface		*ft_create_surface(const int fd, const int x, const int y);

#endif
