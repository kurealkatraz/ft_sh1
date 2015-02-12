/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:42:56 by mgras             #+#    #+#             */
/*   Updated: 2015/02/12 17:36:53 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_fill_holder(int fd)
{
	int		r;
	char	*buf;
	char	*tmp;

	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((r = read(fd, (char*)buf, BUF_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

int		ft_get_next_line(int fd, char **line)
{
	static char	*holder;
	static int	h_swiper = 0;

	if (h_swiper == 0)
		holder = ft_fill_holder(fd);
	ft_putstr(holder);
	ft_putchar('\n');
	line = line;
	return (0);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("src/ft_get_next_line.c", O_RDONLY);
	while (ft_get_next_line(fd, &line) != 0)
		;
	return (0);
}