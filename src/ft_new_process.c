/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 15:42:51 by mgras             #+#    #+#             */
/*   Updated: 2015/03/02 14:44:35 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_split_path(char *value)
{
	char	*path;
	int		i;

	i = 0;
	while (value[i] != '\0' && value[i] != ':')
		i++;
	path = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (value[i] != '\0' && value[i] != ':')
	{
		path[i] = value[i];
		i++;
	}
	path[i] = '\0';
	return (path);
}

t_pth	*ft_new_pth(t_pth *pth, char *path)
{
	t_pth	*newpth;
	int		i;

	i = 0;
	newpth = (t_pth*)malloc(sizeof(t_pth));
	newpth->next = pth;
	while (path[i] != '\0')
		i++;
	newpth->path = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	newpth->path = ft_strcpy(newpth->path, path);
	newpth->next = pth;
	return (newpth);
}

t_pth	*ft_get_pth(t_pth *pth, t_env *env)
{
	t_env	*swap;
	int		i;

	i = 0;
	swap = env;
	while (0 != ft_strcmp(swap->name, "PATH"))
		swap = swap->next;
	while (swap->value[i] != '\0')
	{
		pth = ft_new_pth(pth, ft_split_path(swap->value + i));
		i = i + ft_strlen(pth->path) + 1;
	}
	return (pth);
}


char	*ft_find_bin(char *bin, t_env *env)
{
	t_pth			*pth;
	DIR				*dirp;
	struct dirent	*dire;

	pth = (t_pth*)malloc(sizeof(t_pth));
	pth = NULL;
	pth = ft_get_pth(pth, env);
	while (pth != NULL)
	{
		if (NULL != (dirp = opendir(pth->path)))
		{
			while (NULL != (dire = readdir(dirp)))
			{
				if (0 == ft_strcmp(dire->d_name, bin))
					return (pth->path);
			}
			closedir(dirp);
		}
		pth = pth->next;
	}
	bin = bin;
	return (NULL);
}

void	ft_new_process(char *path, char **argv, t_env *env)
{
	pid_t	pid;
	char	**envp;
	char	*bin;

	bin = (char*)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(argv[0]) + 2));
	bin = ft_strcpy(bin, path);
	bin = ft_strcat(bin, "/");
	bin = ft_strcat(bin, argv[0]);
	pid = fork();
	envp = ft_get_envp(env);
	if (pid == 0)
	{
		execve(bin, argv, envp);
		kill(getpid(), SIGKILL);
	}
	else
		wait(NULL);
}
