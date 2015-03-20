/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 21:54:48 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/07 22:04:37 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))) ||
			!(new->content = (void*)malloc(sizeof(content))) ||
			!(new->content_size = (size_t)malloc(sizeof(size_t))))
		return (NULL);
	if (content != NULL)
	{
		new->content = ft_memcpy(new->content, content, sizeof(content));
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
