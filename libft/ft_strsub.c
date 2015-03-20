/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:53:07 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/06 22:16:29 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*fresh;

	i = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (len-- != 0)
		fresh[i++] = s[start++];
	return (fresh);
}
