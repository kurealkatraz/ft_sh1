/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:30:04 by mgras             #+#    #+#             */
/*   Updated: 2015/03/02 13:56:01 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_tablen(char **tab)
{
	int		ts;

	ts = 0;
	while (tab[ts] != NULL)
		ts++;
	return (ts);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		ss;

	ss = 0;
	while (src[ss])
	{
		dst[ss] = src[ss];
		ss++;
	}
	dst[ss] = '\0';
	return (dst);
}