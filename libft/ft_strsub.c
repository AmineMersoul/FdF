/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:59:34 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 18:21:20 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	int		max;

	if (!s)
		return (0);
	str = ft_strnew(len);
	max = start + len;
	if (max > ft_strlen(s))
		return (0);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		*(str + i) = *(s + start);
		start++;
		i++;
	}
	return (str);
}
