/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:18:03 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/27 14:04:28 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_bin(char *bin, t_env *env)
{
	t_pth	*pth;
	char	*path;

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
