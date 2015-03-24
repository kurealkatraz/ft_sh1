/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_gmb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:27:47 by mgras             #+#    #+#             */
/*   Updated: 2015/03/24 12:27:35 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

 void	ft_cd_errors(int index, char *erred)
 {
 	if (index == 0)
 	{
 		ft_putstr(erred);
 		ft_putstr(" : Is not a Valid name for a Directory\n");
 	}
 	else if (index == 1)
 		ft_putstr("U WOT M8 ? REMOVING HOME JUST LIKE THAT ? OH HELL NO\n");
 	else if (index == 2)
 		ft_putstr("Nope dis ain't goin to work mate\n");
 }

t_env	*ft_home_cd(t_env *env)
{
	t_env	*swp;

	swp = env;
	env = ft_maj_old(env);
	while (swp != NULL)
	{
		if (ft_strcmp(swp->name, "HOME") == 0)
			return (ft_cd(env, swp->value));
		swp = swp->next;
	}
	ft_cd_errors(1, NULL);
	return (env);
}