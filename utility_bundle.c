/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:15:41 by mgras             #+#    #+#             */
/*   Updated: 2015/02/12 16:27:18 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*swap;
	int		ss;

	ss = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	else
	{
		swap = (char*)malloc(sizeof(char) * (ft_strlen(s1) * ft_strlen(s2) + 1));
		while (s1)
			swap[ss++] = *s1++;
		while (s2)
			swap[ss++] = *s2++;
		swap[ss] = '\0';
		free(s1);
		free(s2);
		return (swap);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		s1_swipe;
	int		s2_swipe;

	s1_swipe = 0;
	s2_swipe = 0;
	while (s1[s1_swipe] && (s1[s1_swipe] == s2[s2_swipe]))
	{
		s1_swipe++;
		s2_swipe++;
	}
	return (s1[s1_swipe] - s2[s1_swipe]);
}

int		ft_get_digit(int n)
{
	int		count;

	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int		ft_blank_out(char *str, int size)
{
	int		ss;

	ss = 0;
	while (ss <= size)
		str[ss++] = 0;
	return (0);
}