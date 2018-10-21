/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_x_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:44:54 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/21 21:16:33 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	ft_count_x_y(const int fd, int *x, int *y)
{
	char	*line;
	int		count;

	get_next_line(fd, &line);
	*x = ft_wordcount(line, ' ');
	count = 1;
	while (get_next_line(fd, &line))
		count++;
	*y = count;
}
