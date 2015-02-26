/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 05:33:55 by nowl              #+#    #+#             */
/*   Updated: 2015/02/24 14:20:55 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_fill_member(char *name, char *value, char *member)
{
	int		ts;
	int		ss;

	ts = 0;
	ss = 0;
	while (name[ts])
	{
		member[ts] = name[ts];
		ts++;
	}
	member[ts++] = '=';
	while (value[ss])
		member[ts++] = value[ss++];
	member[ts] = '\0';
	return (member);
}

char	**ft_free_envp(char **envp)
{
	int		ts;

	ts = 0;
	while (envp[ts] != NULL)
		free(envp[ts++]);
	free(envp);
	return (NULL);
}

char	**ft_update_envp(t_env *env, char **envp)
{
	int		ts;
	t_env	*tmp;

	tmp = env;
	ts = 0;
	ft_free_envp(envp);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		ts++;
	}
	envp = (char**)malloc(sizeof(char*) * (ts + 1));
	envp[ts + 1] = NULL;
	tmp = env;
	ts = 0;
	while (tmp != NULL)
	{
		envp[ts] = (char*)malloc(sizeof(char) * (ft_strlen(tmp->name) +
					ft_strlen(tmp->value) + 2));
		envp[ts] = ft_fill_member(tmp->name, tmp->value, envp[ts]);
		ts++;
		tmp = tmp->next;
	}
	return (envp);
}