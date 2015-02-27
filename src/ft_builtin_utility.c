/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebrize <tlebrize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 10:12:20 by tlebrize          #+#    #+#             */
/*   Updated: 2015/02/27 10:29:22 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_is_builtin(char *name)
{
	if (0 == ft_strcmp(name, "exit"))
		exit(0);
	else if(0 == ft_strcmp(name, "cd"))
		return (1);
	else if(0 == ft_strcmp(name, "env"))
		return (1);
	else if(0 == ft_strcmp(name, "setenv"))
		return (1);
	else if(0 == ft_strcmp(name, "unsetenv"))
		return (1);
	return (0);
}
