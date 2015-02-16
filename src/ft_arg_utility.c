/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:46:59 by mgras             #+#    #+#             */
/*   Updated: 2015/02/16 16:49:58 by mgras            ###   ########.fr       */
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
