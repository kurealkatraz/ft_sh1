/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_fnc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:42:02 by mgras             #+#    #+#             */
/*   Updated: 2015/02/27 17:17:01 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		ft_putstr(tmp->name);
		ft_putchar('=');
		ft_putstr(tmp->value);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

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

t_env	*ft_cd(t_env *env, char *dir)
{
	t_env	*tmp;
	char	*val;
	char	*full;

	tmp = env;
	if (getcwd(NULL) != NULL)
	{
		while (ft_strcmp(tmp->name, "PWD") != 0) 
			tmp = tmp->next;
		val = (char*)malloc(sizeof(char) * (ft_strlen(getcwd(NULL))));
		ft_strcpy(val, getcwd(NULL));
		full = (char*)malloc(sizeof(char) * (ft_strlen(val) + ft_strlen("PWD=")));
		ft_strncpy(full, "PWD=", ft_strlen("PWD="));
		ft_strcat(full, val);
		ft_unsetenv(tmp, dir);
		ft_setenv(env, full);
		free(full);
		free(val);
	}
	else
		e_no_such_path(dir);
	return (env);
}
