/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 14:51:02 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/21 14:51:04 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WIREFRAME_H
# define __WIREFRAME_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

void	ft_count_x_y(const int fd, int *x, int *y);
void	ft_create_wireframe(const int fd,
const int x, const int y, int **wireframe);

#endif
