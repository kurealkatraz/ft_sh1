/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:13:15 by mgras             #+#    #+#             */
/*   Updated: 2015/02/22 18:23:09 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_unsetenv_2(t_env *tmp, t_env *save, char *unset_name)
{
	if (ft_strcmp(unset_name, tmp->name) == 0)
	{
		free (tmp->name);
		free (tmp->value);
		save->next = tmp->next;
		free (tmp);
		return (1);
	}
	else
	{
		save = save->next;
		tmp = tmp->next;
		return (0);
	}
}

t_env	*ft_unsetenv(char *unset_name, t_env *env)
{
	t_env	*tmp;
	t_env	*save;

	tmp = env;
	if (ft_strcmp(unset_name, tmp->name) == 0)
	{
		free (tmp->name);
		free (tmp->value);
		env = env->next;
		free (tmp);
		return (env);
	}
	save = tmp;
	tmp = tmp->next;
	while (ft_unsetenv_2(tmp, save, unset_name) != 0)
		;
	return (env);
}

int		ft_check_name(t_env *env, char *full)
{
	t_env	*swap;
	char	*name;
	int		len;

	len = 0;
	while (full[len] != '=' && full[len] != '\0')
		len++;
	name = (char *)malloc(sizeof(char) * (len + 1));
	name = ft_strncpy(name, full, len);
	name[len] = '\0';
	swap = env;
	while (swap != NULL)
	{
		if (0 == ft_strcmp(name, swap->name))
		{
			free(name);
			return (0);
		}
			swap = swap->next;
	}
	free(name);
	return (-1);
}

char	**ft_setenv(char **argv, t_env *env, char **envp)
{
	if (ft_check_name(env, argv[1]) == -1)
		ft_new_env_end(env, argv[1], 0, 0);
	else
		ft_putstr("lolno\n");
	envp = ft_yamete(env, envp);
	return (envp);
}

void	ft_env(t_env *env)
{
	t_env	*swap;
	swap = env;
	while (swap != NULL)
	{
		ft_putstr(swap->name);
		ft_putchar('=');
		ft_putstr(swap->value);
		ft_putchar('\n');
		swap = swap->next;
	}
}
