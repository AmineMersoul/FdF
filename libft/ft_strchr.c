/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:43:15 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 10:43:16 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char*)s;
	while (res[i] != '\0')
	{
		if (res[i] == c)
		{
			return (res + i);
		}
		i++;
	}
	if (res[i] == c)
		return (res + i);
	return (0);
}
