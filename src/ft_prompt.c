/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:48:24 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/17 15:18:10 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_process_arg(char **argv, int argc)
{
	char	*path;

	if (argc > 0)
	{
		path = ft_get_exec_path(argv[0]);
		execve(path, argv, NULL);
		if (path != NULL)
			free(path);
	}
}

void	ft_prompt(char *prompt)
{
	char	**argv;
	char	*buff;
	int		argc;
	int		i;

	buff = (char*)malloc(sizeof(char) * 1024);
	ft_bzero(buff, 1024);
	while (0 != ft_strcmp("exit\n", buff))
	{
		ft_putstr(prompt);
		i = read(0, (char*)buff, 1024);
		buff[i] = '\0';
		argv = ft_strsplit(buff, ' ');
		argc = ft_get_argc(buff, ' ');
		ft_process_arg(argv, argc);
		ft_free_argv(argv, argc);
	}
}
