/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 15:46:17 by mgras             #+#    #+#             */
/*   Updated: 2015/03/21 19:48:13 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include <stdio.h>

char	*ft_read(void)
{
	char	*line;

	if (ft_get_next_line(0, &line) == 1)
		return (line);
	return (NULL);
}

void	ft_prompt(char **envp, t_env *env)
{
	char	*line;
	char	**argv;
	char	*path;

	while (42)
	{
		line = NULL;
		ft_colors(envp);
		if (NULL != (line = ft_read()))
		{
			if (line[0] != '\0')
			{
				line = ft_clean_str(line);
				argv = ft_strsplit(line, ' ');
				if (1 == ft_is_builtin(argv[0]))
				{
					env = ft_builtin(argv, env);
				}
				else
				{
					if ((path = ft_find_bin(argv[0], env)) == NULL)
						ft_putstr("not found\n");
					else
						ft_new_process(path, argv, env);
				}
				ft_free_argv(argv);
				free(line);
				argv = NULL;
			}
		}
		else
			exit(-1);
	}
	envp = envp + 1;
}

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env = NULL;
	env = ft_get_env(env, envp);
	ft_prompt(envp, env);
	argv = argv + 1;
	argc = argc + 1;
	return (0);
}
