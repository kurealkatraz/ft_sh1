/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:01:05 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 17:06:17 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

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
