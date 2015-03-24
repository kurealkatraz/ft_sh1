/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vorpalblade_Snickersnack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 18:36:49 by mgras             #+#    #+#             */
/*   Updated: 2015/03/24 19:32:43 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int		Bentobox_Sushisnatch(char **argv, char *cmp, int pos)
{
	int		cmplen;

	cmplen = 0;
	while (cmp[cmplen] != '=')
		cmplen++;
	while (argv[pos] != NULL)
	{
		if (ft_strncmp(cmp, argv[pos++], cmplen) == 0)
			return (1);
	}
	return (0);
}

void	Bellatrix_Cuddlecunt(char **argv)
{
	int		pos;

	pos = 2;
	while (argv[pos] != NULL)
	{
		if (Bentobox_Sushisnatch(argv, argv[pos], pos + 1) == 0)
			ft_putendl(argv[pos]);
		pos++;
	}
}