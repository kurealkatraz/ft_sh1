/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_pth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowl <nowl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 17:30:31 by mgras             #+#    #+#             */
/*   Updated: 2015/02/24 04:57:54 by nowl             ###   ########.fr       */
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
	new_pth = ft_alloc_path(new_pth, value, pos);
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

t_env	*ft_search_path(t_env *env)
{
	while (ft_strcmp(env->name, "PATH") != 0 && env != NULL)
		env = env->next;
	return (env);
}

t_pth	*ft_fill_path(t_env *env, t_pth *pth)
{
	int		pos;
	t_env	*swap;

	swap = env;
	swap = ft_search_path(swap);
	pth->path = (char*)malloc(sizeof(char) * ft_strlen(getcwd(NULL, 1024)));
	pth->path = getcwd(NULL, 1024);
	pth->next = NULL;
	pos = 0;
	while (pos < (int)ft_strlen(swap->value))
	{
		pth = ft_new_pth_end(pth, &pos, swap->value);
		pos++;
	}
	return (pth);
}
