/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_care.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 13:35:12 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/24 13:35:14 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_env	*ft_minimal_env_gen(t_env *env)
{
	if (env != NULL)
		env = ft_free_all_env(env);
	env = ft_new_env(env, "PATH=/bin");
	env = ft_new_env(env, ft_strjoin("PWD=", getcwd(NULL, PATH_MAX)));
	env = ft_new_env(env, "_=usr/bin/env");
	return (env);
}

t_env	*ft_free_all_env(t_env *env)
{
	t_env	*swp;

	swp = env;
	while (env != NULL)
	{
		swp = env;
		if (env->name)
			free(env->name);
		if (env->value)
			free(env->value);
		env = env->next;
		free(swp);
	}
	return (NULL);
}
