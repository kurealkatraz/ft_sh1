/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:24:55 by mgras             #+#    #+#             */
/*   Updated: 2015/02/26 18:07:16 by tlebrize         ###   ########.fr       */
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
	int		i;

	i = 0;
	line = NULL;
	while (42)
	{
		ft_putstr("/_| _,\n  | /_");
		line = ft_read();
		argv = ft_strsplit((const char*)line, ' ');
		while (argv[i] != NULL)
			ft_putstr(argv[i++]);
		free(line);
		i = 0;
		while (argv[i] != NULL)
			free(argv[i++]);
		free(argv);
		ft_putchar('\n');
	}
	envp = envp;
	env = env;
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
