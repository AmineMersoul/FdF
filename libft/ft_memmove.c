/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:13:19 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/05 16:13:20 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	temp[len];

	if (len > 65535)
		return (0);
	ft_memcpy(temp, src, len);
	ft_memcpy(dest, temp, len);
	return (dest);
}
