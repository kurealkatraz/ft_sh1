/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:48:24 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/16 16:38:24 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_get_argc(char *input, char delim)
{
	char	*clean;
	int		argc;

	clean = ft_get_clean_line(input, ' ', 0);
	argc = ft_tsize(clean, delim);
	argc--;
	free(clean);
	return (argc);
}

void	ft_free_argv(char **argv, int argc)
{
	int		ss;

	ss = 0;
	while (ss <= argc)
		free(argv[ss++]);
	free(argv);
}

void	ft_prompt(char *prompt)
{
	char	**argv;
	char	*buff;
	int		argc;
	int		i;

	buff = (char*)malloc(sizeof(char) * 1024);
	ft_bzero(buff, 1024);
	while (0 != ft_strcmp("exit\n", buff))
	{
		ft_putstr(prompt);
		i = read(0, (char*)buff, 1024);
		buff[i] = '\0';
		argv = ft_strsplit(buff, ' ');
		argc = ft_get_argc(buff, ' ');
		ft_free_argv(argv, argc);
	}
}
