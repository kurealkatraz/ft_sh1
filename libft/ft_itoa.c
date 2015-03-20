/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:27:39 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/09 13:48:01 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_intlen(n);
	if (!(str = (char*)malloc(sizeof(char) * (1 + len))))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while ((len > 0 && str[0] != '-') || (len > 1 && str[0] == '-'))
	{
		len--;
		if (n > 0)
			str[len] = '0' + n % 10;
		else if (n < 0)
			str[len] = '0' + -1 * (n % 10);
		else
			str[len] = '0';
		n = n / 10;
	}
	return (str);
}
