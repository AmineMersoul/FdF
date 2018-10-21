/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:50:09 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/10 17:50:10 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(const char *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			count++;
			continue ;
		}
		i++;
	}
	return (count);
}
