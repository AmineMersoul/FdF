/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 09:43:56 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/09 09:43:59 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(size_t nb, size_t i, size_t j, char *res)
{
	if (nb < 10)
	{
		res[i] = nb + 48;
		res[i + 1] = '\0';
		return (res);
	}
	while (nb != 0)
	{
		res[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	res[i] = '\0';
	i--;
	while (j < i)
	{
		nb = res[j];
		res[j] = res[i];
		res[i] = nb;
		i--;
		j++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	nb;
	int		count;

	count = ft_digitlen(n);
	res = ft_strnew(count);
	if (!res)
		return (0);
	i = 0;
	j = 0;
	nb = n;
	if (n < 0)
	{
		nb = nb * -1;
		res[i] = '-';
		i++;
		j++;
	}
	return (convert(nb, i, j, res));
}
