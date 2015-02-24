/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowl <nowl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:52:03 by mgras             #+#    #+#             */
/*   Updated: 2015/02/24 05:30:18 by nowl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_check_builtin(char **argv)
{
	if (0 == ft_strcmp(argv[0], "cd"))
		return (0);
	else if (0 == ft_strcmp(argv[0], "unsetenv"))
		return (0);
	else if (0 == ft_strcmp(argv[0], "setenv"))
		return (0);
	else if (0 == ft_strcmp(argv[0], "env"))
		return (0);
	else if (0 == ft_strcmp(argv[0], "exit"))
		return (0);
	return(-1);
}

t_env	*ft_run_builtin(char **argv, t_env *env)
{
	if (0 == ft_strcmp(argv[0], "cd"))
		ft_putstr("cd");
	else if (0 == ft_strcmp(argv[0], "unsetenv"))
		ft_unsetenv(env, argv[1]);
	else if (0 == ft_strcmp(argv[0], "setenv"))
		ft_setenv(env, argv[1]);
	else if (0 == ft_strcmp(argv[0], "env"))
		ft_env(env);
	else if (0 == ft_strcmp(argv[0], "exit"))
		return (NULL);
	return(env);
}

char	**ft_clone_envp(char **envp)
{
	char	**envp_clone;
	int		ts;

	ts = 0;
	while (envp[ts] != NULL)
		ts++;
	envp_clone = (char**)malloc(sizeof(char*) * (ts + 1));
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
	env = (t_env*)malloc(sizeof(t_env));
	pth = (t_pth*)malloc(sizeof(t_pth));
	if (argv || argc)
		env = ft_fill_env(envp_clone, env, env);
	pth = ft_fill_path(env, pth);
	ft_prompt("$>", envp_clone, env, pth);
	return (0);
}
