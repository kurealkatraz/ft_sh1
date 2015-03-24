/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 16:42:38 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/24 13:33:41 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int		ft_get_index(char **argv)
{
	int		i;
	int		j;

	i = 2;
	while (argv[i] != NULL)
	{
		j = 1;
		while (argv[i][j] != '\0' && argv[i][j] != '=')
			j++;
		if (argv[i][j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

char	**ft_make_argv(char **argv, int i)
{
	int		size;
	char	**fresh;
	int		j;

	j = 0;
	while (argv[j] != NULL)
		j++;
	size = j - (i - 2);
	fresh = (char**)malloc(sizeof(char*) * size);
	j = 0;
	while (argv[i] != NULL)
		fresh[j++] = ft_strdup(argv[i++]);
	fresh[j] = NULL;
	return (fresh);
}

void			ft_env_i(char **argv, t_env *env)
{
	char	*path;
	int		i;
	t_env	*base;
	char	**arg;

	i = ft_get_index(argv);
	if ((path = ft_find_bin(argv[i], env)) == NULL)
	{
		ft_putstr("nope\n");
		return ;
	}
	arg = ft_make_argv(argv, i);
	base = ft_minimal_env_gen(NULL);
	ft_new_process(path, arg, base);
	base = ft_free_all_env(base);
	free(path);
}
