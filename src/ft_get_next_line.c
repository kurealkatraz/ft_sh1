/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:42:56 by mgras             #+#    #+#             */
/*   Updated: 2015/03/02 18:56:15 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

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
		if (buf[r - 1] == '\n')
		{
			free (buf);
			return (tmp);
		}
	}
	free(buf);
	return (tmp);
}

/*int		ft_process_line(char *holder, int h_swiper, char **line)
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
}*/

int		ft_get_next_line(int fd, char **line)
{
	char	*holder;
	int		len;

	len = 0;
	holder = ft_fill_holder(fd);
	while (holder[len] != '\n' && holder[len] != '\0')
		len++;
	if (!(*line = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (holder[len] != '\n' && holder[len] != '\0')
	{
		(*line)[len] = holder[len];
		len++;
	}
	(*line)[len] = '\0';
	return (1);
}
