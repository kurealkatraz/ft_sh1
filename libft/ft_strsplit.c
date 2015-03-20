/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 16:24:10 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/20 16:24:25 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getwc(const char *str, char c)
{
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	if (str[i] == '\0')
		return (0);
	else if (str[i + 1] == '\0')
		return ((str[0] == c) ? 0 : 1);
	while (str[i + 1] != '\0')
	{
		if ((str[i] == c) && (str[i + 1] != c))
			wc++;
		else if (i == 0 && str[i] != c)
			wc++;
		i++;
	}
	return (wc);
}

static int		ft_getwlen(const char *str, int i, char c)
{
	int		len;

	len = 1;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**fresh;
	int		wc;
	int		i;
	int		len;
	int		j;

	if (!str)
		return (NULL);
	wc = ft_getwc(str, c);
	if (!(fresh = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j != wc)
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		len = ft_getwlen(str, i, c);
		if (!(fresh[j] = ft_strsub(str, i, len)))
			return (NULL);
		i += len;
		j++;
	}
	fresh[j] = NULL;
	return (fresh);
}
