/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:46:15 by mgras             #+#    #+#             */
/*   Updated: 2015/03/04 09:24:28 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_minishell.h"

t_env	*ft_free_member(t_env *current, t_env *saved)
{
	free(current->name);
	free(current->value);
	if (saved != NULL)
		saved->next = current->next;
	else
	{
		saved = current->next;
		free(current);
		return (saved);
	}
	free(current);
	return (saved->next);
}

char	**ft_get_envp(t_env *env)
{
	char	**envp;
	t_env	*swap;
	int		i;
	int		len;

	swap = env;
	i = 0;
	while ((swap = swap->next) != NULL)
		i++;
	envp = (char**)malloc(sizeof(char*) * (i + 1));
	swap = env;
	i = 0;
	while (swap != NULL)
	{
		len = ft_strlen(swap->value) + ft_strlen(swap->name) + 2;
		envp[i] = (char*)malloc(sizeof(char) * len);
		envp[i] = ft_strcat(envp[i], swap->name);
		envp[i] = ft_strcat(envp[i], "=");
		envp[i] = ft_strcat(envp[i], swap->value);
		i++;
		swap = swap->next;
	}
	envp[i] = NULL;
	return (envp);
}

t_env	*ft_new_env(t_env *env, char *full)
{
	t_env	*new_mem;
	int		ts;
	int		ss;

	ts = 0;
	ss = 0;
	new_mem = (t_env*)malloc(sizeof(t_env));
	new_mem->next = env;
	while (full[ts] != '=')
		ts++;
	new_mem->name = (char*)malloc(sizeof(char) * (ts + 1));
	new_mem->value = (char*)malloc(sizeof(char) * (ft_strlen(full) - ts));
	ft_strncpy(new_mem->name, full, ts);
	ts++;
	while (full[ts])
		new_mem->value[ss++] = full[ts++];
	new_mem->value[ss] = '\0';
	return (new_mem);
}

t_env	*ft_get_env(t_env *env, char **envp)
{
	int		ts;

	ts = 0;
	while (envp[ts + 1] != NULL)
		ts++;
	while (ts >= 0)
		env = ft_new_env(env, envp[ts--]);
	return (env);
}
