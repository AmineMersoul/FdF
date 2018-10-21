/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:28:32 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 11:28:34 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	aatoi(const char *str, int i)
{
	long long int	nb;

	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			break ;
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}

int						ft_atoi(const char *str)
{
	long long int	nb;
	int				i;
	int				flag;

	i = 0;
	flag = 0;
	if (ft_isempty(str))
		return (0);
	while (str[i] < 33 && str[i] != '\e')
		i++;
	if (str[i] == '-')
		flag = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	nb = aatoi(str, i);
	if (flag == 1)
		nb *= -1;
	if (ft_islong(nb, str) != 1)
		return (ft_islong(nb, str));
	return (nb);
}
