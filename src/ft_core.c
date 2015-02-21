/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:52:03 by mgras             #+#    #+#             */
/*   Updated: 2015/02/21 13:12:30 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;
	t_pth	*pth;

	if (argv || argc)
		env = ft_fill_env(envp);
	pth = ft_fill_path(env);
	ft_prompt("$>", envp, env, pth);
	return (0);
}
