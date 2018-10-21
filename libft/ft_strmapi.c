/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:44:53 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 17:44:54 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		*(str + i) = f(i, *(s + i));
	return (str);
}
