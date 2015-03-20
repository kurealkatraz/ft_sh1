/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:44:28 by tlebrize          #+#    #+#             */
/*   Updated: 2015/03/06 18:10:32 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		value;
	int		i;
	int		r;

	value = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	r = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '+' || r == -1) ? i + 1 : i;
	while (str[i] != '\0')
	{
		value *= 10;
		if (0 != ft_isdigit(str[i]))
			value += str[i] - '0';
		else
		{
			value /= 10;
			return (value * r);
		}
		i++;
	}
	return (value * r);
}
