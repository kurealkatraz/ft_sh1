/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 14:00:48 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 15:44:10 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_daijobu(char *name, char *val)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(val) + 2));
	while (name[i])
	{
		str[i] = name[i];
		i++;
	}
	str[i++] = '=';
	while (val[j])
		str[i++] = val[j++];
	return (str);
}

char	**ft_yamete(t_env *env, char **envp)
{
	t_env	*tmp;
	int		ts;

	tmp = env;
	ts =0;
	while (envp[ts] != NULL)
		free(envp[ts++]);
	free (envp);
	ts = 0;
	while (tmp != NULL && ts++)
		tmp = tmp->next;
	envp = (char**)malloc(sizeof(char*) * (ts + 1));
	envp[ts + 1] = NULL;
	tmp = env;
	ts = 0;
	while (tmp != NULL)
	{
		envp[ts++] = ft_daijobu(tmp->name, tmp->value);
		tmp = tmp->next;
	}
	return (envp);
}