/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:34:59 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/05 20:35:00 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*string;
	int		size;
	int		i;

	size = ft_strlen(src);
	string = (char*)malloc(sizeof(*string) * (size + 1));
	if (!string)
		return (0);
	i = 0;
	while (i < size)
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
