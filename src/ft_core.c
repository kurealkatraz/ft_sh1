/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:52:03 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 15:08:19 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	**ft_builtin_setenv(char **argv, t_env *env, char **envp)
{
	if (ft_check_name(env, argv[1]) == -1)
		ft_new_env_end(env, argv[1]);
	else
		ft_putstr("lolno\n");
	envp = ft_yamete(env, envp);
	return (envp);
}

void	ft_builtin_env(t_env *env)
{
	t_env	*swap;

	swap = env;
	while (swap != NULL)
	{
		ft_putstr(swap->name);
		ft_putchar('=');
		ft_putstr(swap->value);
		ft_putchar('\n');
		swap = swap->next;
	}
}

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
		ft_builtin_setenv(argv, env, envp);
		return (0);
	}
	else if (0 == ft_strcmp(argv[0], "env"))
	{
		ft_builtin_env(env);
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
