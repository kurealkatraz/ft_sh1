/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:24:55 by mgras             #+#    #+#             */
/*   Updated: 2015/02/26 16:06:07 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env = NULL;
	env = ft_get_env(env, envp);
	argv = argv;
	argc = argc;
	envp = envp;
	return (0);
}