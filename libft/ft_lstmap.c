/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 22:28:49 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/09 13:41:07 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*swap;
	t_list	*tmp;

	tmp = f(lst);
	if ((fresh = ft_lstnew(tmp->content, tmp->content_size)))
	{
		swap = fresh;
		lst = lst->next;
		while (lst != NULL)
		{
			tmp = f(lst);
			if (!(swap->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			swap = swap->next;
			lst = lst->next;
		}
	}
	return (fresh);
}
