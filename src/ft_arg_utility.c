/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:46:59 by mgras             #+#    #+#             */
/*   Updated: 2015/02/17 15:22:09 by mgras            ###   ########.fr       */
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

int		ft_check_cmd(char *line, char *cmd)
{
	char	*tmp_cmp;
	int		i;

	i = 0;
	while(line[i] != ':')
		i++;
	tmp_cmp = (char*)malloc(sizeof(char) * (i) + 1);
	i = 0;
	while (line [i] != ':')
	{
		tmp_cmp[i] = line[i];
		i++;
	}
	tmp_cmp[i] = '\0';
	if (ft_strcmp(tmp_cmp, cmd) == 0)
	{
		free(tmp_cmp);
		return (1);
	}
	free(tmp_cmp);
	return (0);
}

char	*ft_get_path(char *line)
{
	char	*path;
	int		cmdlen;
	int		pathlen;

	cmdlen = 0;
	while (line[cmdlen] != ':')
		cmdlen++;
	pathlen = ft_strlen(line) - (cmdlen + 1);
	path = (char*)malloc(sizeof(char) * (pathlen + 1));
	pathlen = 0;
	cmdlen++;
	while (line[cmdlen])
		path[pathlen++] = line[cmdlen++];
	path[pathlen] = '\0';
	return (path);
}

char	*ft_get_exec_path(char *cmd)
{
	char	*line;
	char	*path;
	int		fd;
	int		index;

	fd = open("./usr_local_bin", O_RDONLY);
	index = 0;
	while (ft_get_next_line(fd, &line) != 0)
	{
		if (ft_check_cmd(line, cmd) == 1 && index == 0)
		{
			index = 1;
			path = ft_get_path(line);
		}
	}
	close(fd);
	if (index == 1)
		return (path);
	return (NULL);
}