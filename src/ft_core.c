/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:52:03 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 15:49:04 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_check_builtin(char **argv, t_env *env, char **envp)
{
	if (0 == ft_strcmp(argv[0], "cd"))
	{
		ft_putstr("builtin_cd");
		return (0);
	}
	else if (0 == ft_strcmp(argv[0], "unsetenv"))
	{
		ft_putstr("builtin_unsetenv\n");
		return (0);
	}
	else if (0 == ft_strcmp(argv[0], "setenv"))
	{
		ft_setenv(argv, env, envp);
		return (0);
	}
	else if (0 == ft_strcmp(argv[0], "env"))
	{
		ft_env(env);
		return (0);
	}
	return(-1);
}

char	**ft_clone_envp(char **envp)
{
	char	**envp_clone;
	int		ts;

	ts = 0;
	while (envp[ts] != NULL)
		ts++;
	envp_clone = (char**)malloc(sizeof(char**) * (ts + 1));
	envp_clone[ts + 1] = NULL;
	ts = 0;
	while (envp[ts] != NULL)
	{
		envp_clone[ts] = (char*)malloc(sizeof(char) * (ft_strlen(envp[ts])));
		ft_strcpy(envp_clone[ts], envp[ts]);
		ts++;
	}
	return (envp_clone);
}

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	**envp_clone;
	t_pth	*pth;

	envp_clone = ft_clone_envp(envp);
	if (argv || argc)
		env = ft_fill_env(envp);
	pth = ft_fill_path(env);
	ft_prompt("$>", envp_clone, env, pth);
	return (0);
}
