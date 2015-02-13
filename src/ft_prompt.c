/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:48:24 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/13 14:04:17 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_prompt(char *prompt)
{
	char	*buff;
	int		i;

	while (0 != ft_strcmp("exit\n", buff))
	{
		ft_putstr(prompt);
		if (NULL == (buff = ft_fill_holder(0)))
			return ;
		ft_putstr(buff);
	}
}
