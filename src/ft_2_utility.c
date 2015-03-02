/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 09:58:46 by mgras             #+#    #+#             */
/*   Updated: 2015/03/02 18:13:14 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

/*int		ft_get_clean_len(int start, int end, char *str, char delim)
{
	int		len;

	len = 0;
	while (str[start] == delim && str[start] != '\0')
		start++;
	end = ft_strlen(str);
	while (str[end] == delim && end >= start)
		end--;
	while (start < end)
	{
		if (str[start] == delim)
		{
			len++;
			while (str[start] == delim)
				start++;
		}
		else
		{
			len++;
			start++;
		}
	}
	return (len);
}

int		ft_get_end(char *str, char delim)
{
	int		ss;

	ss = 0;
	while (str[ss])
		ss++;
	while (str[ss] == delim)
		ss--;
	return (ss);
}

char	*ft_get_clean_line(char *str, char delim)
{
	char	*clean_str;
	int		cs;
	int		ts;
	int		ss;

	ts = ft_get_clean_len(0, 0, str, delim);
	clean_str = (char*)malloc(sizeof(char) * ts);
	ss = 0;
	cs = 0;
	while (str[ss] == delim)
		ss++;
	while (ss < ft_get_end(str, delim))
	{
		if (str[ss] == delim)
		{
			clean_str[cs++] = str[ss];
			while (str[ss] == delim)
				ss++;
		}
		else
			clean_str[cs++] = str[ss++];
	}
	clean_str[ss] = '\0';
	return (clean_str);
}*/

#include <stdio.h> // YAMETE

char	**ft_alloc_tab(char *str, char c)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		j = (str[i++] == c ? j + 1 : j);
	new_tab = (char**)malloc(sizeof(char*) * (j + 2));
	new_tab[j + 1] = NULL;
	return (new_tab);
}


int		ft_get_clean_len(char *str, char c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
		len += (str[i++] == c ? 0 : 1);
	if (2 == ft_strlen(str))
		return (len);
	i = 0;
	while (str[i + 1] != '\0' && str[i] == c)
		i++;
	while (str[i + 1] != '\0')
	{
		len += ((str[i] == c && str[i + 1] != c) ? 1 : 0);
		i++;
	}
	return (len);
}

char	*ft_get_clean_line(char *str, char c)
{
	char	*clean;
	int		len;
	int		i;

	len = ft_get_clean_len(str, c);
	clean = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	len = 0;
	while (str[i] == c && str[i + 1] != '\0')
		i++;
	while (str[i + 1] != '\0')
	{
		if ((str[i] == c && str[i + 1] != c) || str[i] != c)
			clean[len++] = str[i];
		i++;
	}
	if (str[i] != c)
		clean[len++] = str[i];
	clean[len] = '\0';
	return (clean);
}

char	**ft_strsplit(const char *str, char c)
{
	char	**new_tab;
	char	*clean_str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	clean_str = ft_get_clean_line((char*)str, c);
	new_tab = ft_alloc_tab(clean_str, c);
	while (clean_str[i] != '\0')
	{
		j = i;
		while (clean_str[j] != c && clean_str[j] != '\0')
			j++;
		new_tab[k] = (char*)malloc(sizeof(char) * (j - i + 1));
		new_tab[k] = ft_strncpy(new_tab[k], clean_str + i, j - i);
		new_tab[k++][j - i] = '\0';
		i = (j + 1);
	}
	free(clean_str);
	return (new_tab);
}
