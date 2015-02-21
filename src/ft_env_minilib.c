/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_minilib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:42:04 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 15:33:25 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_get_value_len(char *full, int name_size)
{
	int		len;

	while (full[len])
		len++;
	return (len - name_size);
}

int		ft_get_name_len(char *full)
{
	int		len;

	len = 0;
	while (full[len] != '=')
		len++;
	return (len);
}

char	*ft_fill_value(char *value, char *full)
{
	int		ss;
	int		ts;

	ss = 0;
	ts = 0;
	while (full[ss] != '=')
		ss++;
	ss++;
	while (full[ss])
		value[ts++] = full[ss++];
	value[ts] = '\0';
	return (value);
}

char	*ft_fill_name(int len, char *name, char *full)
{
	int		ss;

	ss = 0;
	while (ss < len)
	{
		name[ss] = full[ss];
		ss++;
	}
	name[ss] = '\0';
	return (name);
}
