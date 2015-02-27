/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 09:58:46 by mgras             #+#    #+#             */
/*   Updated: 2015/02/27 12:07:29 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_get_clean_len(int start, int end, char *str, char delim)
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
}

char	**ft_alloc_tab(char *str, char c)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		j = (str[i++] == c ? j + 1 : j);
	new_tab = (char**)malloc(sizeof(char*) * (j + 1));
	new_tab[j + 1] = NULL;
	return (new_tab);
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