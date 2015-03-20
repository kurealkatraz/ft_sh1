/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:19:27 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/05 18:50:00 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (((char*)s)[i] != '\0')
		i++;
	if (c == '\0')
		return (((char*)s) + i);
	while (i != -1)
	{
		if (((char*)s)[i] == c)
			return (((char*)s) + i);
		i--;
	}
	return (NULL);
}
