/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:33:26 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/07 16:33:27 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_strnew(len1 + len2);
	if (!res)
		return (0);
	i = -1;
	while (++i < len1)
	{
		res[i] = s1[i];
	}
	j = -1;
	while (++j < len2)
	{
		res[i++] = s2[j];
	}
	return (res);
}
