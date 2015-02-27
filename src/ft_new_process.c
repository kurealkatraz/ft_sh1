/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 15:42:51 by mgras             #+#    #+#             */
/*   Updated: 2015/02/27 15:47:03 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_split_path(char *value)
{
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
	path[i] == '\0';
	return (path)
}

t_pth	*ft_get_pth(t_env *env)
{
	t_env	*swap;
	int		len;
	int		i;

	i = 0;
	len = 0;
	swap = env;
	while (0 != ft_strcmp(swap->name, "PATH"))
		swap = swap->next;
	while (swap->value[i] != '\0')
	{
		pth = (t_pth*)malloc(sizeof(t_pth));
		pth->path = ft_split_path(swap->value + i)
		i += ft_strlen(pth->path) + 1;
		pth = pth->next
	}
	ft_putstr("lolno"); //YAMETE
	return (NULL);
}

char	*ft_find_bin(char *bin, t_env *env)
{
	t_pth	*pth;
	char	*path;

	pth = (t_pth*)malloc(sizeof(t_pth));
	pth = NULL;
	pth = ft_get_path(env);
	while (pth != NULL)
	{
		
	}
}

void	ft_new_process(char *path, char **argv, t_env *env)
{
	pid_t	pid;
	char	**envp;

	pid = fork();
	envp = ft_get_envp(env);
	if (pid == 0)
	{
		execve(path, argv, envp);
		kill(getpid(), SIGKILL);
	}
	else
		wait(NULL);
}