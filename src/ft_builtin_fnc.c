/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_fnc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:42:02 by mgras             #+#    #+#             */
/*   Updated: 2015/03/13 18:54:32 by mgras            ###   ########.fr       */
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
	free(name);
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
	char	*swap;
	t_env	*tmp;

	tmp = env;
	while (tmp->next != NULL && 0 != ft_strcmp(tmp->name, "PWD"))
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (env);
	swap = (char*)malloc(sizeof(char) * (8 + ft_strlen(tmp->value)));
	swap = ft_strcpy(swap, "OLDPWD=");
	swap = ft_strcat(swap, tmp->value);
	tmp = env;
	while (tmp->next != NULL && 0 != ft_strcmp(tmp->name, "OLDPWD"))
		tmp = tmp->next;
	if (tmp == NULL)
		return (env);
	if (chdir(tmp->value) != 0)
		ft_putstr("error : chdir is feeling sick\n");
	env = ft_maj_pwd(env);
	env = ft_unsetenv(env, "OLDPWD");
	env = ft_setenv(env, swap);
	return (env);
}

t_env	*ft_maj_pwd(t_env *env)
{
	t_env	*swap;
	char	*full;
	char	*buff;

	swap = env;
	while (swap->next != NULL && 0 != ft_strcmp(swap->name, "PWD"))
		swap = swap->next;
	if (swap->next != NULL)
		env = ft_unsetenv(env, "PWD");
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
	if (dir[0] == '-')
		return (env = ft_oldpwd(env));
	chdir(dir);
	env = ft_unsetenv(env, "PWD");
	env = ft_maj_pwd(env);
	return (env);
}
