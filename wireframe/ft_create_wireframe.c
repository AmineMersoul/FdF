/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_wireframe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:48:10 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/22 17:11:26 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

int		**ft_create_wireframe(const int fd,
const int x, const int y)
{
	char	*line;
	int		i;
	int		j;
	char	**res;
	int		**wireframe;

	wireframe = (int **)malloc(sizeof(int *) * y);
	wireframe[0] = (int *)malloc(sizeof(int) * x * y);
	i = 0;
	while (++i < y)
		wireframe[i] = (*wireframe + x * i);
	i = 0;
	while (get_next_line(fd, &line))
	{
		res = ft_strsplit((const char*)line, ' ');
		j = 0;
		while (res[j] != 0)
		{
			wireframe[i][j] = ft_atoi((const char *)res[j]);
			j++;
		}
		i++;
	}
	return (wireframe);
}
