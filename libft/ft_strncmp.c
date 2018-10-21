/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:23:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 11:23:28 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 1;
	if (n == 0)
		return (0);
	while (*s1++ == *s2++)
	{
		if (i >= n)
			return (0);
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)*--s1 - (unsigned char)*--s2);
}
