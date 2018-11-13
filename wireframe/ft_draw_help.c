/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:02:29 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/13 16:30:15 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	ft_draw_help(void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	if (params->help == 0)
		return ;
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	32, 32, 0xFFFFFF, "presse 'esc' key to exit");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	32, 64, 0xFFFFFF, "presse 'c' key to clear screen");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	400, 32, 0xFFFFFF, "presse 'up' or 'down' keys to change height");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	400, 64, 0xFFFFFF, "click on the screen to draw lignes");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	900, 32, 0xFFFFFF, "presse 'w, s, a, d' keys to move");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	900, 64, 0xFFFFFF, "scroll or press '+, -' keys to zoom");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	1300, 32, 0xFFFFFF, "presse 'v' key to chage views");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	1300, 64, 0xFFFFFF, "presse 'r, g ,b' keys to change colors");
}
