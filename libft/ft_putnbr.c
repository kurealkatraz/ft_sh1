/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 21:55:54 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/09 13:46:38 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void			ft_putnbr(int n)
{
	size_t	len;
	char	*str;

	if (n < 0)
		ft_putchar('-');
	len = ft_intlen(n);
	if (!(str = (char*)malloc(sizeof(char) * (1 + len))))
		return ;
	str[len] = '\0';
	while (len-- > 0)
	{
		if (n > 0)
			str[len] = '0' + n % 10;
		else if (n < 0)
			str[len] = '0' + -1 * (n % 10);
		else
			str[len] = '0';
		n = n / 10;
	}
	ft_putstr(str);
	free(str);
}
