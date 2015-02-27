/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:24:55 by mgras             #+#    #+#             */
/*   Updated: 2015/02/27 14:12:41 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_read(void)
{
	char	*line;

	if (ft_get_next_line(0, &line) == 1)
		return (line);
	else
		exit (0);
	return (NULL);
}

void	ft_prompt(char **envp, t_env *env)
{
	char	*line;
	char	**argv;

	line = NULL;
	while (42)
	{
		ft_putstr("/_| _.\n  | /_ ");
		line = ft_read();
		argv = ft_strsplit((const char*)line, ' ');
		if (1 == ft_is_builtin(argv[0]))
			env = ft_builtin(argv, env);
		else
		{
			if ((path = ft_find_bin(argv[0], env)) == NULL)
				ft_putstr("not found\n");
			else
				ft_new_process(path, argv, env);`
		}
		ft_free_argv(argv);
		argv = NULL;
		ft_putchar('\n');
	}
	envp = envp;
}

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env = NULL;
	env = ft_get_env(env, envp);
	ft_prompt(envp, env);
	argv = argv;
	argc = argc;
	return (0);
}
