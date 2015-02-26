/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_0_libstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:39:05 by mgras             #+#    #+#             */
/*   Updated: 2015/02/24 13:03:09 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
