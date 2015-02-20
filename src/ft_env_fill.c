/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:01:05 by mgras             #+#    #+#             */
/*   Updated: 2015/02/20 17:50:36 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_env	*ft_env_alloc(t_env *env, char *full)
{
	int		name_size;
	int		value_size;

	name_size = ft_get_name_len(full);
	env->name = (char*)malloc(sizeof(char) * (name_size + 1));
	ft_fill_name(name_size, env->name, full);
	value_size = ft_get_value_len(full, name_size);
	env->value = (char*)malloc(sizeof(char) * (value_size + 1));
	ft_fill_value(env->value, full);
	return (env);
}

t_env	*ft_fill_env(char **envp)
{
	t_env	*env;
	int		ts;

	ts = 0;
	env = (t_env*)malloc(sizeof(t_env));
	ft_env_init(env, envp);
	ts++;
	while (envp[ts])
		env = ft_new_env_end(env, envp[ts++]);
	return (env);
}