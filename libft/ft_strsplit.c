/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 19:21:17 by mgras             #+#    #+#             */
/*   Updated: 2015/03/23 11:01:28 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		**ft_alloc_tab(char *str, char c)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		j = (str[i++] == c ? j + 1 : j);
	new_tab = (char**)malloc(sizeof(char*) * (j + 2));
	new_tab[j + 2] = NULL;
	return (new_tab);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**new_tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	printf("str <%s>\n", str);
	new_tab = ft_alloc_tab((char*)str, c);
	while (str[i] != '\0')
	{
		j = i;
		while (str[j] != c && str[j] != '\0')
			j++;
		new_tab[k] = (char*)malloc(sizeof(char) * (j - i + 1));
		new_tab[k] = ft_strncpy(new_tab[k], str + i, j - i);
		new_tab[k][j - i] = '\0';
		printf("argv[%d] <%s>\n", k, new_tab[k]);
		k++;
		new_tab[k] = NULL;
		if (j != '\0')
			i = (j + 1);
		else
			i = j;
	}
	printf("argv[%d] <%s>\n", k, new_tab[k]);
	return (new_tab);
}
