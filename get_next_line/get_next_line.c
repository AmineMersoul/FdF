/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:19:01 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/17 10:39:05 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

int		read_one_line(char **saved, char **line, int fd)
{
	int i;

	i = 0;
	while (saved[fd][i] != '\n' && saved[fd][i] != '\0')
		i++;
	if (saved[fd][i] == '\n')
	{
		*line = ft_strsub(saved[fd], 0, i);
		saved[fd] = ft_strdup(saved[fd] + i + 1);
	}
	else if (saved[fd][i] == '\0')
	{
		*line = ft_strdup(saved[fd]);
		ft_strdel(&saved[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*saved[256];
	char		buff[BUFF_SIZE + 1];
	int			r;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strnew(BUFF_SIZE + 1);
		saved[fd] = ft_strjoin(saved[fd], buff);
		if (ft_strrchr(buff, '\n'))
			break ;
	}
	if (r < 0)
		return (-1);
	else if (r == 0 && (saved[fd] == NULL || saved[fd][0] == '\0'))
		return (0);
	return (read_one_line(saved, line, fd));
}
