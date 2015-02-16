/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libstr_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 13:45:53 by mgras             #+#    #+#             */
/*   Updated: 2015/02/16 16:20:55 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function is purely
** here to retrieve a pseudo
** argv from the usr imput
*/

#include "ft_sh1.h"

char	*ft_get_clean_line(char *line, char delim, int ss)
{
	char	*clean_line;
	int		start;
	int		end;

	end = ft_strlen(line) - 2;
	start = 0;
	while (line[start] == delim)
		start++;
	while (line[end] == delim && end >= start)
		end--;
	clean_line = (char*)malloc(sizeof(char) * (end - start + 1));
	while (start <= end)
	{
		if (line[start] == delim)
		{
			clean_line[ss++] = line[start++];
			while (line[start] == delim)
				start++;
		}
		else
			clean_line[ss++] = line[start++];
	}
	clean_line[ss] = '\0';
	return (clean_line);
}

int		ft_ssize(char *clean_line, char delim, int pos)
{
	int		size;

	size = 0;
	while (clean_line[pos] != delim && clean_line[pos])
	{
		pos++;
		size++;
	}
	return (size);
}

int		ft_tsize(char *clean_line, char delim)
{
	int		ss;
	int		size;

	ss = 0;
	size = 0;
	while (clean_line[ss++])
		if (clean_line[ss] == delim)
			size++;
	return (size + 1);
}

char	**ft_get_argv(char *line, char d)
{
	char	**argv;
	int		pos;
	int		ss;
	int		ts;

	ts = 0;
	pos = 0;
	argv = (char**)malloc(sizeof(char*) * (ft_tsize(line, d) + 1));
	while (line[pos] && ts <= ft_tsize(line, d))
	{
		ss = 0;
		argv[ts] = (char*)malloc(sizeof(char) * (ft_ssize(line, d, pos) + 1));
		while (line[pos] != d && line[pos])
			argv[ts][ss++] = line[pos++];
		argv[ts][ss] = '\0';
		pos++;
		ts++;
	}
	return (argv);
}

char	**ft_strsplit(char *line, char delim)
{
	char	**argv;

	argv = ft_get_argv(ft_get_clean_line(line, delim, 0), delim);
	return (argv);
}
