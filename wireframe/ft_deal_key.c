/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:16:38 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/13 21:42:56 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

static void	other(t_draw_params *params, int key)
{
	if (key == 8)
	{
		if (params->colorize == 1)
			params->colorize = 0;
		else
			params->colorize = 1;
		ft_draw_help(params);
		params->color = ft_create_color(255, 255, 255);
	}
	if (key == 7)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		ft_draw_help(params);
	}
	if (key == 122)
	{
		if (params->help == 0)
			params->help = 1;
		else
			params->help = 0;
	}
}

static void	key_v(t_draw_params *params)
{
	if (params->view == 1)
		params->view = 0;
	else
		params->view = 1;
}

static void	zoom_extrude_move(t_draw_params *params, int key)
{
	if (key == 126)
		params->extrude += 0.02;
	if (key == 125)
		params->extrude -= 0.02;
	if (key == 78)
	{
		if (params->scale > 0.5)
			params->scale -= 0.5;
	}
	if (key == 69)
		params->scale += 0.5;
	if (key == 13)
		params->offset.y -= 50;
	if (key == 1)
		params->offset.y += 50;
	if (key == 2)
		params->offset.x += 50;
	if (key == 0)
		params->offset.x -= 50;
}

static void	change_color(t_draw_params *params, int key)
{
	if (key == 15)
		params->color.r -= 10;
	if (key == 5)
		params->color.g -= 10;
	if (key == 11)
		params->color.b -= 10;
}

int			ft_deal_key(int key, void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	if (key == 53)
		exit(0);
	if (key == 8 || key == 7 || key == 122)
		other(params, key);
	if (key == 126 || key == 125 || key == 78 || key == 69
	|| key == 13 || key == 1 || key == 2 || key == 0)
		zoom_extrude_move(params, key);
	if (key == 15 || key == 5 || key == 11)
		change_color(params, key);
	if (key == 9)
		key_v(params);
	if (key != 7)
		ft_redraw(params);
	return (0);
}
