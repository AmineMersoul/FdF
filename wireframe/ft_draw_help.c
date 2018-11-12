/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:02:29 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/12 15:05:36 by amersoul         ###   ########.fr       */
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
	400, 32, 0xFFFFFF, "presse key 'up' or 'down' to change height");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	400, 64, 0xFFFFFF, "click on the screen to draw lignes");
}
