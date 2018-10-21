/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:51:37 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/10 17:51:38 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wordcut(const char *str, int index, char c)
{
	char	*res;
	int		count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	j = index;
	while (str[index] != c && str[index] != '\0')
	{
		count++;
		index++;
	}
	res = (char*)malloc(sizeof(*res) * (count + 1));
	while (str[j] != c && str[j] != '\0')
	{
		res[i] = str[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
