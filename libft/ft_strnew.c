/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:21:49 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/06 15:21:50 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	res = (char*)malloc(sizeof(char) * (size + 1));
	if (res)
	{
		ft_bzero(res, size + 1);
		return (res);
	}
	return (0);
}
