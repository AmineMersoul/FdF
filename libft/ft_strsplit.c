/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:42:30 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/07 18:42:31 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**strsplit_checking(char **res, const char *s, char c)
{
	if (!s || !c)
		return (0);
	res = malloc(sizeof(char*) * (ft_wordcount(s, c) + 1));
	if (!res)
		return (0);
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		count;

	res = 0;
	res = strsplit_checking(res, s, c);
	if (!res)
		return (0);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			res[count] = malloc((ft_wordlen(s, i, c) + 1) * sizeof(char*));
			res[count] = ft_wordcut(s, i, c);
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	res[count] = 0;
	return (res);
}
