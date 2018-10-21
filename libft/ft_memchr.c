/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:07:41 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/05 17:07:43 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*csrc;
	char	cc;

	csrc = (char*)s;
	cc = (char)c;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == cc)
			return (&csrc[i]);
		i++;
	}
	return (0);
}
