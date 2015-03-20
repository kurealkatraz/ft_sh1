/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:19:40 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/09 13:45:50 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		s1len;

	i = 0;
	s1len = ft_strlen(s1);
	while (i < n && *s2 != '\0')
		s1[s1len + i++] = *s2++;
	s1[s1len + i++] = '\0';
	return (s1);
}
