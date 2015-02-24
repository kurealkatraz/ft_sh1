/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowl <nowl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 06:26:25 by nowl              #+#    #+#             */
/*   Updated: 2015/02/24 06:39:08 by nowl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_env	*ft_cd(t_env *env, char *path)
{
	char	*full;
	int		ts;
	int		ss;

	ts = 4;
	ss = 0;
	if (chdir(path) == 0)
	{
		ft_unsetenv(env, "PWD");
		full = (char*)malloc(sizeof(char) * (ft_strlen(path) +
				ft_strlen("PWD") + 1));
		ft_strcpy(full, "PWD=");
		while (path[ss++])
			full[ts++] = path[ss++];
		full[ts] = '\0';
		ft_setenv(env, full);
		free (full);
	}
	else
	{
		ft_putstr("ft_minishell: cd: There is no such Directory: ");
		ft_putstr(path);
		ft_putchar('\n');
	}
	return (env);
}