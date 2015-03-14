/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildtin_gmb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:27:47 by mgras             #+#    #+#             */
/*   Updated: 2015/03/14 11:04:23 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 void	ft_cd_errors(int index, char *erred)
 {
 	if (index == 0)
 	{
 		ft_putstr(erred);
 		ft_putstr(" : Is not a Valid name for a Directory\n");
 	}
 }
