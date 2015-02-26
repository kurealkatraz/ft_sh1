/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 06:26:25 by nowl              #+#    #+#             */
/*   Updated: 2015/02/26 10:34:55 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_clean_path(t_env *env, char *path)
{
	char	*full;
	t_env	*tmp;

	tmp = env;
	while (ft_strcmp(tmp->name, "PWD") != 0)
		tmp = tmp->next;
	full = (char*)malloc(sizeof(char) * (ft_strlen(tmp->value) + ft_strlen("PWD=") 
			+ ft_strlen(path) + 2));
	full[0] = 'P';
	full[1] = 'W';
	full[2] = 'D';
	full[3] = '=';
	full[4] = '\0';
	full = ft_strjoin(full, tmp->value);
	full[ft_strlen(tmp->value) + ft_strlen("PWD=")] = '/';
	full = ft_strjoin(full, path);
	full[ft_strlen(tmp->value) + ft_strlen("PWD=") + ft_strlen(path) + 2] = '\0';
	return (full);
}

t_env	*ft_cd(t_env *env, char *path)
{
	char	*full;

	if (chdir(path) == 0)
	{
		full = ft_clean_path(env, path);
		env = ft_unsetenv(env, "PWD");
		ft_putstr(full);
		env = ft_setenv(env, full);
		chdir(full);
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
