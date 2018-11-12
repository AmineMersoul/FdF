/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:24:13 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/24 20:28:21 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_dec_hex(int nb)
{
	char	*base;
	char	*res;
	char	temp;
	int		i;
	
	base = "0123456789ABCDEF";
	res = malloc(sizeof(char) * 2);
	if (nb < 0 || nb > 255)
		return 0;
	i = 0;
	while (nb > 0)
	{
		res[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	if (i == 2)
	{
		temp = res[0];
		res[0] = res[1];
		res[1] = temp;
	}
	else
	{
		temp = res[0];
		res[0] = 0 + 48;
		res[1] = temp;
	}
	return (res);
}
