/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:46:15 by mgras             #+#    #+#             */
/*   Updated: 2015/02/26 16:22:10 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

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
	while (ts > 0)
		env = ft_new_env(env, envp[ts--]);
	return (env);
}