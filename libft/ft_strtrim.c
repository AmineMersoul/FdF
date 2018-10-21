/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:53:35 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/07 16:53:36 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_count(char const *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] < 33 && s[i] != '\0')
	{
		if (s[i + 1] == '\0')
			break ;
		i++;
	}
	count++;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	while (s[i] < 33 && count > 0)
	{
		i--;
		count--;
	}
	return (count);
}

static char	*trim(char *res, char const *s, size_t i)
{
	size_t	j;

	while (s[i] < 33 && s[i] != '\0')
	{
		if (s[i + 1] == '\0')
			break ;
		res[0] = s[i + 1];
		i++;
	}
	j = 0;
	while (s[i] != '\0')
	{
		res[j] = s[i];
		j++;
		i++;
	}
	j--;
	while (res[j] < 33)
	{
		res[j] = '\0';
		j--;
	}
	return (res);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!s)
		return (0);
	len = trim_count(s);
	res = ft_strnew(len);
	if (!res)
		return (0);
	i = 0;
	return (trim(res, s, i));
}
