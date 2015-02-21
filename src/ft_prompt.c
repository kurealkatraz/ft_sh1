/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:48:24 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/21 13:11:32 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_make_path(char *dest, char *path, char *file)
{
	int		i;
	int		ss;

	i = 0;
	ss = 0;
	dest = (char*)malloc(sizeof(char) *
		(ft_strlen(path) + ft_strlen(file) + 2));
	while (path[i])
	{
		dest[i] = path[i];
		i++;
	}
	dest[i++] = '/';
	while (file[ss])
		dest[i++] = file[ss++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_find_bin(char *bin_name, t_pth *pth, char *path)
{
	DIR				*dirs;
	struct dirent	*dire;
	t_pth			*swap;

	swap = pth;
	while (swap != NULL)
	{
		dirs = opendir(swap->path);
		if (dirs != NULL)
		{
			while ((dire = readdir(dirs)) != NULL)
			{
				if (0 == ft_strcmp(dire->d_name, bin_name))
				{
					path = ft_make_path(path, swap->path, bin_name);
					return (path);
				}
			}
			closedir(dirs);
		}
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

void	ft_process_arg(char **argv, t_env *env, t_pth *pth, char **envp)
{
	char	*path;

	path = ft_find_bin(argv[0], pth, NULL);
	if (path != NULL && env)
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

void	ft_prompt(char *prompt, char **envp, t_env *env, t_pth *pth)
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
			if (0 != ft_strcmp("exit\n", buff) && argc >= 0)
			{
				ft_process_arg(argv, env, pth, envp);
				ft_free_argv(argv, argc);
			}
		}
	}
}
