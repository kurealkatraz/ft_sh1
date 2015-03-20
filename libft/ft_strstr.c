/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:33:20 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/05 16:32:12 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		j;

	j = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		j = 0;
		while (s2[j] != '\0' && s2[j] == *(char*)s1 + j)
			j++;
		if (s2[j] == '\0')
			return ((char*)s1);
		*(char*)s1 = *(char*)s1 + 1;
	}
	return (NULL);
}
