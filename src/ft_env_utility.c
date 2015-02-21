/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:20:47 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 17:06:16 by mgras            ###   ########.fr       */
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

t_env	*ft_env_init(t_env *env, char **envp)
{
	env->next = NULL;
	env = ft_env_alloc(env, envp[0]);
	return (env);
}

void	ft_free_env(t_env *env)
{
	t_env	*tmp;

	while (env != NULL)
	{
		free(env->name);
		free(env->value);
		tmp = env;
		env = env->next;
		free(tmp);
	}
}

t_env	*ft_new_env_end(t_env *env, char *full)
{
	t_env	*new_env;
	t_env	*swap;

	new_env = (t_env*)malloc(sizeof(t_env));
	new_env = ft_env_alloc(new_env, full);
	new_env->next = NULL;
	if (env->next == NULL)
		env->next = new_env;
	else
	{
		swap = env;
		while (swap->next != NULL)
			swap = swap->next;
		swap->next = new_env;
	}
	return (env);
}
