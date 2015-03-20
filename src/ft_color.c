/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 10:40:28 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/19 17:23:59 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static char	*ft_getend(char *dst, char *src, int j)
{
	int		i;

	i = ft_strlen(src);
	while (j > 0)
		j -= (src[i--] == '/' ? 1 : 0);
	dst = ft_strncpy(dst, src, i);
	return (dst);
}

static char	*ft_getpath(void)
{
	char	*fresh;
	char	*buff;
	int		i;
	int		j;

	if (!(buff = (char*)malloc(sizeof(char*) * (PATH_MAX + 1))) ||
			!(buff = getcwd(buff, PATH_MAX)) ||
			!(fresh = (char*)malloc(sizeof(char) * (ft_strlen(buff) + 1))))
		return (ft_strdup("MadMoon"));
	i = ft_strlen(buff);
	j = 0;
	while (i > 0)
		j += (buff[i--] == '/') ? 1 : 0;
	if (j < 4)
		fresh = ft_strcpy(fresh, buff);
	else
		fresh = ft_getend(fresh, buff, j);
	free(buff);
	return (fresh);
}

static char	*ft_gettime(void)
{
	char	t[26];
	time_t tloc;

	time(&tloc);
	ft_strcpy(t, ctime(&tloc));
	return (ft_strndup(t + 11, 8));
}

static char	*ft_getname(char **envp)
{
	int		i;
	char	*fresh;

	i = 0;
	if (!envp)
		return (ft_strdup("Anon"));
	while ((envp[i] != NULL) && 0 != ft_strncmp(envp[i], "LOGNAME", 7))
		i++;
	if (envp[i] == NULL)
		fresh = ft_strdup("Anon");
	else
		fresh = ft_strdup(envp[i] + 8);
	return (fresh);
}

void		ft_colors(char **envp)
{
	char	*name;
	char	*time;
	char	*path;

	time = ft_gettime();
	name = ft_getname(envp);
	path = ft_getpath();
	ft_putstr(C_CYAN);
	ft_putstr(name);
	ft_putstr(C_RED" - ");
	ft_putstr(C_GREEN);
	ft_putstr(time);
	ft_putstr(C_NONE"\n");
	ft_putstr(C_MAGENTA);
	ft_putstr(path);
	ft_putstr(" : "C_NONE);
	free(path);
	free(name);
	free(time);
}
