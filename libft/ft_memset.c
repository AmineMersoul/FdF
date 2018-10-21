/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:50:11 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/04 15:50:13 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*cptr;
	char	cvalue;

	cptr = (char*)b;
	cvalue = (char)c;
	i = 0;
	while (i < len)
	{
		cptr[i] = cvalue;
		i++;
	}
	return (b);
}
