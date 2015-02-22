/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 14:00:48 by mgras             #+#    #+#             */
/*   Updated: 2015/02/22 19:42:00 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	**ft_yamete(t_env *env, char **envp)
{
	t_env	*swap;
	int		i;
	char	**new_envp;

	swap = env;
	i = 0;
	while (envp[i++] != NULL)
		free(envp[i]);
	free(envp);
	i = 0;
	while (swap != NULL)
	{
		i++;
		swap = swap->next;
	}
	swap = env;
	i = 0;
	new_envp = (char**)malloc(sizeof(char*) * (i + 1));
	while (swap != NULL)
	{
		new_envp[i] = (char*)malloc(sizeof(char) * (ft_strlen(env->name) +
					ft_strlen(env->value) + 2));
		new_envp[i] = ft_strcpy(new_envp[i], env->name);
		new_envp[i] = ft_strjoin(new_envp[i], "=");
		new_envp[i] = ft_strjoin(new_envp[i], env->value);
		swap = swap->next;
		i++;
	}
	return (new_envp);
}
