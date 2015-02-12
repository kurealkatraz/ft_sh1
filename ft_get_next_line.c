/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:42:56 by mgras             #+#    #+#             */
/*   Updated: 2015/02/12 17:03:31 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_fill_holder(int fd)
{
	int		r;
	char	*buf;
	char	*holder;

	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((r = read(fd, (char*)buf, BUF_SIZE)) > 0)
	{
		buf[r] = '\0';
		holder = ft_strjoin(holder, buf);
	}
	free(buf);
	return (holder);
}

int		ft_get_next_line(int fd, char **line)
{
	static char	*holder;
	static int	h_swiper = 0;

	if (h_swiper = 0)
		holder = ft_fill_holder(fd);
}