/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 20:27:59 by mgras             #+#    #+#             */
/*   Updated: 2015/02/13 13:44:02 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_input(char *input)
{
	char	*line;
	int		fd;
	int		index;

	index = 0;
	fd = open("../cmd.arch")
	while (get_next_line(fd, &line))
	{
		if (ft_strcmp(line, input) == 0)
			index = 1;
	}
	return (index);
}