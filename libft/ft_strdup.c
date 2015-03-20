/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:02:28 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/25 18:18:13 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	new = ft_strcpy(new, s1);
	return (new);
}
