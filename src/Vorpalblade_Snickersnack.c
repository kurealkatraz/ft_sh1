/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vorpalblade_Snickersnack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 18:36:49 by mgras             #+#    #+#             */
/*   Updated: 2015/03/24 19:12:32 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		Bentobox_Sushisnatch(char **argv, char cmp, int pos, int markpos)
{
	while (pos < markpos)
	{
		if (ft_strcmp(cmp, argv[pos]) == 0)
			return (1);
	}
	return (0);
}

char	**Bellatrix_Cuddlecunt(char **argv, int markpos)
{
	int		pos;

	pos = 0;
	while (pos < markpos)
	{
		if (Bentobox_Sushisnatch(argv, argv[pos], pos, markpos) == 0)
			ft_putendl(argv[pos])
		pos++;
	}
}