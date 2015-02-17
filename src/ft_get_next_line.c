/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:42:56 by mgras             #+#    #+#             */
/*   Updated: 2015/02/17 15:48:48 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_fill_holder(int fd)
{
	int		r;
	char	*buf;
	char	*tmp;

	r = 0;
	if (!(buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (NULL);
	tmp = NULL;
	while ((r = read(fd, (char*)buf, BUF_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

int		ft_process_line(char *holder, int h_swiper, char **line)
{
	int		ls;
	int		ls_bis;

	ls = 0;
	ls_bis = 0;
	while (holder[h_swiper + ls] != '\0' && holder[h_swiper + ls] != '\n')
		ls++;
	if (!(*line = (char*)malloc(sizeof(char) * (ls + 1))))
		return (0);
	while (holder[h_swiper] != '\0' && holder[h_swiper] != '\n')
		(*line)[ls_bis++] = holder[h_swiper++];
	(*line)[ls_bis] = '\0';
	return (h_swiper + 1);
}

int		ft_get_next_line(int fd, char **line)
{
	static char	*holder;
	static int	h_swiper = 0;

	if (h_swiper == 0)
		holder = ft_fill_holder(fd);
	if (holder[h_swiper] == '\n')
	{
		(*line)[0] = '\n';
		(*line)[1] = '\0';
		h_swiper++;
		return (1);
	}
	h_swiper = ft_process_line(holder, h_swiper, line);
	if ((*line)[0] == '\0')
	{
		free(holder);
		h_swiper = 0;
		return (0);
	}
	return (1);
}
