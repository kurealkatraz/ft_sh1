/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:14:36 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/25 18:16:49 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		s1len;

	i = 0;
	s1len = ft_strlen(s1);
	while (*s2 != '\0')
		s1[s1len + i++] = *s2++;
	s1[s1len + i] = '\0';
	return (s1);
}
