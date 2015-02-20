/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:51:50 by mgras             #+#    #+#             */
/*   Updated: 2015/02/20 15:10:39 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
#include <stdio.h> //YAMETE

# define BUF_SIZE 42

/*
** ft_prompt.c
*/
void	ft_process_arg(char **argv, int argc, char **envp);
void	ft_prompt(char *prompt, char **envp);
void	ft_new_process(const char *path, char *const *argv, char *const *envp);
/*
** ft_get_next_line.c
*/
char	*ft_fill_holder(int fd);
int		ft_get_next_line(int fd, char **line);
int		ft_process_line(char *holder, int h_swiper, char **line);

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
** ft_get_argv.c
*/
char	*ft_get_clean_line(char *line, char delim, int ss);
int		ft_ssize(char *clean_line, char delim, int pos);
int		ft_tsize(char *clean_line, char delim);
char	**ft_get_argv(char *line, char d);
char	**ft_strsplit(char *line, char delim);

/*
** ft_arg_utility.c
*/
int		ft_get_argc(char *input, char delim);
void	ft_free_argv(char **argv, int argc);
int		ft_check_cmd(char *line, char *cmd);
char	*ft_get_path(char *line);
char	*ft_get_exec_path(char *cmd);

#endif
