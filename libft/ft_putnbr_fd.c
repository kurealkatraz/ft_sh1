/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:25:11 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/09 13:46:48 by tlebrize         ###   ########.fr       */
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

void			ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	*str;

	if (n < 0)
		ft_putchar_fd('-', fd);
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
	ft_putstr_fd(str, fd);
	free(str);
}
