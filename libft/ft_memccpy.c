/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:20:34 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/05 14:20:36 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*
	ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdest;
	char	cc;

	csrc = (char *)src;
	cdest = (char *)dst;
	cc = (char)c;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		if (csrc[i] == cc)
			break ;
		i++;
	}
	if (csrc[i] == cc)
	{
		return (&cdest[i + 1]);
	}
	return (0);
}
