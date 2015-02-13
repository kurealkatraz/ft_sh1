/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:48:24 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/13 15:02:53 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_free_argv(char **argv, char *buff, char d)
{
	int		ss;

	ss = 0;
	while (ss <= ft_tsize(buff, d))
		free(argv[ss++]);
	free(argv);
}

void	ft_prompt(char *prompt)
{
	char	*buff;
	int		i;
	char	**argv;

	buff = (char*)malloc(sizeof(char) * 1024);
	ft_bzero(buff, 1024);
	while (0 != ft_strcmp("exit\n", buff))
	{
		ft_putstr(prompt);
		i = read(0, (char*)buff, 1024);
		buff[i] = '\0';
		argv = ft_get_argv(buff, ' ');
		/*
		** PROCESS ARGV HERE
		*/
		ft_free_argv(argv, buff, ' ');
	}
}
