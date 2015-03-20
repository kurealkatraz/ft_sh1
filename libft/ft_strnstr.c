/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:53:58 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/05 19:10:59 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while ((char)s1[i] != '\0' && i != n)
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] != '\0' && s2[j] == s1[i + j]
				&& i + j != n)
			j++;
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
