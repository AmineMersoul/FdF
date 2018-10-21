/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:56:49 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 16:56:51 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (0);
	i = -1;
	while (*(s + ++i))
		*(str + i) = f(*(s + i));
	return (str);
}
