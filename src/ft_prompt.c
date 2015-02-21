/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:48:24 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/21 11:56:42 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_make_path(char *dest, char *path, char *file)
{
	path = (char*)malloc(sizeof(char) * (ft_strlen(path)
				+ ft_strlen(file) + 2));
	ft_strjoin(path, path);
	ft_strjoin(path, "/");
	ft_strjoin(path, file);
	return (path);
}

char	*ft_find_bin(char *bin_name, t_pth *pth, char *path)
{
	DIR				*dirs;
	struct dirent	*dire;
	t_pth			*swap;

	swap = pth
	while (swap != NULL)
	{
		dirs = open(swap->path);
		while ((dire = readdir(dirs)) != NULL)
		{
			if (0 == ft_strcmp(dire->d_name, bin_name))
			{
				path = ft_make_path(path, swap->path, bin_name);
				return (path);
			}
		}
		closedir(dirs);
		swap = swap->next;
	}
	return (NULL);
}

void	ft_new_process(const char *path, char *const *argv, char *const *envp)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid == 0)
		execve(path, argv, envp);
	else if (pid > 0)
		wait(&stat);
	else
		ft_putstr("Fork Error\n");
}

void	ft_process_arg(char **argv, int argc, char **envp)
{
	char	*path;

	if (argc >= 0)
	{
		path = ft_get_exec_path(argv[0]);
		if (path != NULL)
		{
			ft_new_process(path, argv, envp);
			free(path);
		}
		else
		{
			ft_putstr("ft_minishell1: comand not found : ");
			ft_putstr(argv[0]);
			ft_putchar('\n');
		}
	}
}

void	ft_prompt(char *prompt, char **envp)
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
		if (i > 1)
		{
			argv = ft_strsplit(buff, ' ');
			argc = ft_get_argc(buff, ' ');
			if (0 != ft_strcmp("exit\n", buff))
			{
				ft_process_arg(argv, argc, envp);
				ft_free_argv(argv, argc);
			}
		}
	}
}
