/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:52:03 by mgras             #+#    #+#             */
/*   Updated: 2015/02/20 18:14:28 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		main(int argc, char **argv, char **envp)
{
	argv = argv;
	argc = argc;
/*	env = ft_fill_env(envp);
	pth = ft_fill_path(env);
	env = env;
	pth = pth;*/
	ft_prompt("λ-is-Δ →", envp);
	return (0);
}
