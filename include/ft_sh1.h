/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:51:50 by mgras             #+#    #+#             */
/*   Updated: 2015/02/13 14:38:36 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUF_SIZE 42

/*
** ft_prompt.c
*/
void	ft_prompt(char *prompt);
/*
** ft_get_next_line.c
*/
char	*ft_fill_holder(int fd);
int		ft_get_next_line(int fd, char **line);
/*
** ft_libstr_0.c
*/
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
void	ft_putchar(char c);
/*
** ft_libstr_1.c
*/
void	ft_putstr(char *str);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_intlen(int n);
void	ft_putnbr(int n);
void	ft_bzero(char *str, size_t size);
/*
** ft_libstr_2.c
*/
char	**ft_strsplit(char *line, char delim);
char	**ft_get_argv(char *line, char delim);
int		ft_tszie(char *clean_line, char delim);
int		ft_ssize(char *clean_line, char delim, int pos);
char	*ft_get_clean_line(char *line, char delim, int ss);
#endif
