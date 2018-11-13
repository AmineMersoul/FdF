/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:59:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/13 21:14:35 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

static void	mouse_down(t_draw_params *params)
{
	if (params->scale > 0.5)
		params->scale -= 0.5;
	ft_redraw(params);
}

static void	mouse_up(t_draw_params *params)
{
	params->scale += 0.5;
	ft_redraw(params);
}

static void	mouse_shift_down(t_draw_params *params)
{
	if (params->scale > 5)
		params->scale -= 5;
	ft_redraw(params);
}

static void	mouse_shift_up(t_draw_params *params)
{
	params->scale += 5;
	ft_redraw(params);
}

int			ft_deal_mouse(int button, int x, int y, void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	if (button == 1 && ft_check_win_click(x, y))
		ft_get_coordinates(x, y, param);
	if (button == 5)
		mouse_down(params);
	if (button == 4)
		mouse_up(params);
	if (button == 7)
		mouse_shift_down(params);
	if (button == 6)
		mouse_shift_up(params);
	return (0);
}
