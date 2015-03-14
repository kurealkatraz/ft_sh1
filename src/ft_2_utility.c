/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 09:58:46 by mgras             #+#    #+#             */
/*   Updated: 2015/03/14 18:28:30 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int		ft_getwc(char *str, char c)
{
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	if (str[i] == '\0')
		return (0);
	else if (str[i + 1] == '\0')
		return (str[0] == c ? 0 : 1);
	while (str[i + 1] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			wc++;
		else if (i == 0 && str[i] != c)
			wc++;
		i++;
	}
	return (wc);
}

static int		ft_getwlen(char *str, int i, char c)
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

static char		*ft_strsub(char *str, int start, int len)
{
	char	*fresh;
	int		i;

	if (!(fresh = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (len-- > 1)
		fresh[i++] = str[start++];
	fresh[i] = '\0';
	return (fresh);
}

char			**ft_strsplit(char *str, char c)
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
