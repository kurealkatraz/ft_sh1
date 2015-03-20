/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:26:13 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/05 19:52:10 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (((char*)s)[i] != '\0')
	{
		if (((char*)s)[i] == c)
			return (((char*)s) + i);
		i++;
	}
	if (c == '\0')
		return (((char*)s) + i);
	return (NULL);
}
