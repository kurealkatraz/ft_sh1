/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:52:03 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 15:15:52 by mgras            ###   ########.fr       */
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

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;
	t_pth	*pth;

	if (argv || argc)
		env = ft_fill_env(envp);
	pth = ft_fill_path(env);
	ft_prompt("$>", envp, env, pth);
	return (0);
}
