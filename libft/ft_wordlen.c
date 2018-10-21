/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:45:50 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/10 17:45:51 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordlen(const char *str, int index, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[index] != c && str[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}
