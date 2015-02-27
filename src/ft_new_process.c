/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:18:03 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/27 14:12:44 by mgras            ###   ########.fr       */
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