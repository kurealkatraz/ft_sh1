/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_fnc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:42:02 by mgras             #+#    #+#             */
/*   Updated: 2015/03/04 17:20:14 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_env	*ft_setenv(t_env *env, char *mod)
{
	env = ft_new_env(env, mod);	//XDDD LE EPIC FEDORA MASTER
	return (env);				//WWW.CODEMASTER.COM FOR FULL TUTORIAL
}

t_env	*ft_unsetenv(t_env *env, char *mod)
{
	t_env	*tmp;
	t_env	*save;
	int		r;

	tmp = env;
	save = env;
	r = 42;
	if ((r = ft_strcmp(tmp->name, mod)) != 0)
		tmp = tmp->next;
	else
	{
		env = env->next;
		ft_free_member(tmp, NULL);
		return (env);
	}
	while((r = ft_strcmp(tmp->name, mod)) != 0)
	{
		save = tmp;
		tmp = tmp->next;
	}
	if (r != 0)
		e_no_match_env(mod);
	else
		tmp = ft_free_member(tmp, save);
	return (env);
}

t_env	*ft_maj_pwd(t_env *env)
{
	char	*full;
	char	*buff;

	buff = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
	buff = getcwd(buff, PATH_MAX);
	full = (char*)malloc(sizeof(char) * (ft_strlen(buff) + 5));
	full = ft_strcpy(full, "PWD=");
	full = ft_strcat(full, buff);
	env = ft_setenv(env, full);
	free(buff);
	free(full);
	return (env);
}

t_env	*ft_cd(t_env *env, char *dir)
{
	env = ft_maj_pwd(env);
	chdir(dir);
	env = ft_unsetenv(env, "PWD");
	env = ft_maj_pwd(env);
	return (env);
}
