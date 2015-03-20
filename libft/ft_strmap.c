/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:35:01 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/06 18:39:23 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	size_t		len;
	char		*dst;

	i = 0;
	len = 1 + ft_strlen(s);
	if (!(dst = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (*s != '\0')
		dst[i++] = f(*s++);
	return (dst);
}
