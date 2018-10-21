/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:55:46 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/05 17:55:47 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	unsigned char	*end;
	int				res;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	end = cs1 + n;
	res = 0;
	while (1)
	{
		if (res || cs1 >= end)
			break ;
		res = (int)*cs1++ - (int)*cs2++;
		if (res || cs1 >= end)
			break ;
	}
	return (res);
}
