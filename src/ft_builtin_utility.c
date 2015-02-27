/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 10:12:20 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/27 10:44:38 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_is_builtin(char *name)
{
	if (0 == ft_strcmp(name, "exit"))
		exit(0);
	else if(0 == ft_strcmp(name, "cd"))
		return (1);
	else if(0 == ft_strcmp(name, "env"))
		return (1);
	else if(0 == ft_strcmp(name, "setenv"))
		return (1);
	else if(0 == ft_strcmp(name, "unsetenv"))
		return (1);
	return (0);
}

t_env	*ft_builtin(char **argv, t_env *env)
{
	if (0 == ft_strcmp(argv[0], "cd"))
		return (env);
	else if (0 == ft_strcmp(argv[0], "env"))
		return (ft_builtin_env(env));
	else if (0 == ft_strcmp(argv[0], "setenv"))
		return (env);
	else if (0 == ft_strcmp(argv[0], "unsetenv"))
		return (env);
	else
		return (env);
}

t_env	*ft_builtin_env(t_env *env)
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
	return (env);
}