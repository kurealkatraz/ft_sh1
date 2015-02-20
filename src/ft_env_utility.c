/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:20:47 by mgras             #+#    #+#             */
/*   Updated: 2015/02/20 17:15:25 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_env	*ft_env_init(t_env *env, char **envp)
{
	env->next = NULL;
	env = ft_flash_alloc(env, envp[0]);
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

t_env	*ft_new_end(t_env *env, char *full)
{
	t_env	*new_env;
	t_env	*swap;

	new_env = (t_env*)malloc(sizeof(t_env));
	new_env = ft_flash_alloc(new_env, full);
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