/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 10:37:44 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/26 10:37:49 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_env	*ft_new_env_end(t_env *env, char *full, int ts, int ss)
{
	t_env	*tmp;

	tmp  = env;
	if (tmp->next == NULL)
		tmp = ft_new_env_link(tmp);
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp = ft_new_env_link(tmp);
	}
	tmp->next = NULL;
	tmp->name = (char*)malloc(sizeof(char) * ft_get_nam_len(full) + 1);
	tmp->value = (char*)malloc(sizeof(char) * ft_get_va_len(full) + 1);
	while (full[ts] != '=')
		tmp->name[ss++] = full[ts++];
	tmp->name[ss] = '\0';
	ss = 0;
	ts++;
	while (full[ts])
		tmp->value[ss++] = full[ts++];
	tmp->value[ss] = '\0';
	return (env);
}

t_env	*ft_new_env_link(t_env *env)
{
	t_env	*new_link;

	new_link = (t_env*)malloc(sizeof(t_env));
	env->next = new_link;
	new_link->next = NULL;
	return (new_link);
}

int		ft_get_nam_len(char *name)
{
	int		ss;

	ss = 0;
	while (name[ss] != '=')
		ss++;
	return (ss);
}

int		ft_get_va_len(char *val)
{
	int		ss;
	int		ts;

	ss = 0;
	ts = 0;
	while (val[ss] != '=')
		ss++;
	ss++;
	while (val[ss++])
		ts++;
	return (ts);
}

t_env	*ft_fill_env(char **envp, t_env *env, t_env *tmp)
{
	int		ts;
	int		ss;
	int		i;

	ts = 0;
	while (envp[ts] != NULL)
	{
		tmp->name = (char*)malloc(sizeof(char) * ft_get_nam_len(envp[ts]) + 1);
		tmp->value = (char*)malloc(sizeof(char) * ft_get_va_len(envp[ts]) + 1);
		ss = 0;
		i = 0;
		while (envp[ts][ss] != '=')
			tmp->name[i++] = envp[ts][ss++];
		tmp->name[i] = '\0';
		ss++;
		i = 0;
		while (envp[ts][ss])
			tmp->value[i++] = envp[ts][ss++];
		tmp->value[i] = '\0';
		ts++;
		if (envp[ts] != NULL)
			tmp = ft_new_env_link(tmp);
	}
	return (env);
}
