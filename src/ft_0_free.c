/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 10:53:54 by mgras             #+#    #+#             */
/*   Updated: 2015/03/14 16:24:13 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_free_argv(char **argv)
{
	int		ts;

	ts = 0;
	while (argv[ts] != NULL)
	{
		argv[ts] = NULL;
		free(argv[ts++]);
	}
	free(argv);
	argv = NULL;
}