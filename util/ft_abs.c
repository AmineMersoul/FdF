/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:10:57 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/22 11:13:37 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}
