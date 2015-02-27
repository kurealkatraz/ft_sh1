/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:57:25 by mgras             #+#    #+#             */
/*   Updated: 2015/02/27 14:03:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		ss;

	ss = 0;
	while (src[ss] && ss < n)
	{
		dst[ss] = src[ss];
		ss++;
	}
	dst[ss] = '\0';
	return (dst);
}

char	*ft_strcat(char *s1, char *s2, char delim)
{
	char	*full;
	int		ts;
	int		ss;

	full = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	ts = 0;
	ss = 0;
	while (s1[ts])
	{
		full[ts] = s1[ts];
		ts++;
	}
	full[ts++] = delim;
	while(s2[ss])
		full[ts++] = s2[ss++]
	full[ts] = '\0';
	return (full);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*swap;
	int		ss;

	ss = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	swap = (char*)malloc(sizeof(char) * (ft_strlen(s1) * ft_strlen(s2) + 1));
	while (*s1)
		swap[ss++] = *s1++;
	while (*s2)
		swap[ss++] = *s2++;
	swap[ss] = '\0';
	return (swap);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		s1_swipe;
	int		s2_swipe;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	s1_swipe = 0;
	s2_swipe = 0;
	while (s1[s1_swipe] && (s1[s1_swipe] == s2[s2_swipe]))
	{
		s1_swipe++;
		s2_swipe++;
	}
	return (s1[s1_swipe] - s2[s1_swipe]);
}
