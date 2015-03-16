/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_fnc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:42:02 by mgras             #+#    #+#             */
/*   Updated: 2015/03/16 16:07:14 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_env	*ft_setenv(t_env *env, char *mod)
{
	t_env	*swap;
	char	*name;
	int		len;

	swap = env;
	while (mod[len] != '=' && mod[len] != '\0')
		len++;
	name = (char*)malloc(sizeof(char) * (len + 1));
	name = ft_strncpy(name, mod, len);
	while (swap != NULL)
	{
		if (0 == ft_strcmp(name, swap->name))
		{
			env = ft_unsetenv(env, name);
			env = ft_setenv(env, mod);
			return (env);
		}
		else if (swap->next == NULL)
		{
			swap->next = ft_new_env(NULL, mod);
			return (env);
		}
		swap = swap->next;
	}
	return (env);
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

t_env	*ft_oldpwd(t_env *env)
{
	t_env	*swp;

	swp = env;
	while (ft_strcmp(swp->name, "OLDPWD") != 0 && swp->next != NULL)
		swp = swp->next;
	return (env = ft_cd(env, swp->value));
}

t_env	*ft_maj_pwd(t_env *env)
{
	t_env	*swap;
	char	*buff;

	swap = env;
	while (swap != NULL && 0 != ft_strcmp(swap->name, "PWD"))
		swap = swap->next;
	buff = (char*)malloc(sizeof(char) * (PATH_MAX + 5));
	if (swap == NULL)
	{
		buff = ft_strcpy(buff, "PWD=");
		buff = ft_strcat (buff, getcwd(NULL, PATH_MAX));
		env = ft_setenv(env, buff);
		return (env);
	}
	free(swap->value);
	buff = getcwd(buff, PATH_MAX);
	swap->value = (char*)malloc(sizeof(char) * (ft_strlen(buff) + 1));
	swap->value = ft_strcpy(swap->value, buff);
	free(buff);
	return (env);
}

t_env	*ft_maj_old(t_env *env)
{
	t_env	*swp;
	t_env	*pwd;

	swp = env;
	pwd = env;
	while (ft_strcmp(swp->name, "OLDPWD") != 0 && swp->next != NULL)
		swp = swp->next;
	while (ft_strcmp(pwd->name, "PWD") != 0 && pwd->next)
		pwd = pwd->next;
	if (ft_strcmp(swp->name, "OLDPWD") != 0)
		ft_setenv(env, ft_strjoin("OLDPWD=./", pwd->value));
	else
	{
		env = ft_unsetenv(env, "OLDPWD");
		env = ft_setenv(env, ft_strjoin("OLDPWD=", pwd->value));
	}
	return (env);
}

t_env	*ft_cd(t_env *env, char *dir)
{
	if (dir == NULL || dir[0] == '~')
		return (ft_home_cd(env));
	if (dir[0] == '-')
		return (env = ft_oldpwd(env));
	chdir(dir);
	env = ft_maj_old(env);
	env = ft_maj_pwd(env);
	return (env);
}
