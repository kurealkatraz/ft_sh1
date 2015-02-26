/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:57:25 by mgras             #+#    #+#             */
/*   Updated: 2015/02/26 15:59:49 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t		ss;

	ss = 0;
	while (src[ss] && ss < n)
	{
		dst[ss] = src[ss];
		ss++;
	}
	dst[ss] = '\0';
	return (0);
}