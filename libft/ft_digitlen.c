/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:40:35 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/10 17:40:36 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitlen(int n)
{
	size_t	temp;
	int		count;

	count = 0;
	temp = n;
	if (n < 0)
	{
		count++;
		temp = temp * -1;
	}
	if (temp < 10)
	{
		return (count + 1);
	}
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}
