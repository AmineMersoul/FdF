/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:10:50 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/09 14:10:51 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = malloc(sizeof(t_list) * 1);
	if (!res)
		return (0);
	if (!content)
	{
		res->content = 0;
		res->content_size = 0;
	}
	else
	{
		res->content = ft_memalloc(content_size);
		ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next = 0;
	return (res);
}
