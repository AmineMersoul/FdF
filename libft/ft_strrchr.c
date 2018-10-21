/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:53:20 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 10:53:21 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = (char*)s;
	i = ft_strlen(res);
	while (i >= 0)
	{
		if (res[i] == c)
		{
			return (res + i);
		}
		i--;
	}
	return (0);
}
