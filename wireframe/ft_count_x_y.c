/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_x_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:44:54 by amersoul          #+#    #+#             */
/*   Updated: 2018/11/12 16:21:33 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

int	ft_count_x_y(const int fd, int *x, int *y)
{
	char	*line;
	int		count;

	get_next_line(fd, &line);
	*x = ft_wordcount(line, ' ');
	count = 1;
	while (get_next_line(fd, &line))
	{
		if (*x != ft_wordcount(line, ' '))
			return 0;
		count++;
	}
	*y = count;
	return 1;
}
