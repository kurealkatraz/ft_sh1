/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 19:11:24 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/07 15:17:08 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(char const *s)
{
	int		i;
	size_t	len;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (1);
	i = 0;
	len = 1 + ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
	{
		i++;
		len--;
	}
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i > 0)
	{
		i--;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	int		i;
	char	*fresh;

	len = ft_getlen(s);
	i = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (len == 1)
	{
		fresh[0] = '\0';
		return (fresh);
	}
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	fresh = ft_strsub(s, i, len - 1);
	return (fresh);
}
