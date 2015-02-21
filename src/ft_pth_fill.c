/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pth_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 17:30:31 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 12:50:54 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_pth	*ft_alloc_path(t_pth *pth, char *value, int *pos)
{
	int		value_len;

	value_len = *pos;
	while (value[value_len] != ':')
		value_len++;
	pth->path = (char*)malloc(sizeof(char) * (value_len + 1));
	value_len = 0;
	while (value[*pos] != ':' && value[*pos] != '\0')
	{
		pth->path[value_len++] = value[*pos];
		*pos = *pos + 1;
	}
	pth->path[value_len] = '\0';
	return (pth);
}

t_pth	*ft_new_pth_end(t_pth *pth, int *pos, char *value)
{
	t_pth	*tmp;
	t_pth	*new_pth;

	new_pth = (t_pth*)malloc(sizeof(t_pth));
	new_pth->next = NULL;
	ft_alloc_path(new_pth, value, pos);
	if (pth->next == NULL)
		pth->next = new_pth;
	else
	{
		tmp = pth;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_pth;
	}
	return (pth);
}

t_pth	*ft_fill_path(t_env *env)
{
	t_pth	*pth;
	int		pos;

	pos = 0;
	pth = (t_pth*)malloc(sizeof(t_pth));
	pth = ft_alloc_path(pth, env->value, &pos);
	pth->next = NULL;
	while (pos < (int)ft_strlen(env->value))
	{
		pos++;
		pth = ft_new_pth_end(pth, &pos, env->value);
	}
	return (pth);
}
