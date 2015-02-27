/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:34:46 by mgras             #+#    #+#             */
/*   Updated: 2015/02/27 12:09:38 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL
# define FT_MINISHELL
# define BUF_SIZE 42

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

/*
**	ft_core.c
*/
char	**ft_fill_envp_clone(char **clone, char **origin);
void	ft_prompt(char **envp, t_env *env);

/*
**	ft_get_next_line.c
*/
char	*ft_fill_holder(int fd);
int		ft_process_line(char *holder, int h_swiper, char **line);
int		ft_get_next_line(int fd, char **line);

/*
**	ft_env.c
*/
t_env	*ft_new_env(t_env *env, char *full);
t_env	*ft_get_env(t_env *env, char **envp);

/*
**	ft_0_utility.c
*/
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(const char *str);
int		ft_tablen(char **tab);
char	*ft_strcpy(char *dst, const char *src);

/*
**	ft_1_utility.c
*/
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);

/*
**	ft_2_utility.c (Strsplit)
*/
int		ft_get_clean_len(int start, int end, char *str, char delim);
int		ft_get_end(char *str, char delim);
char	*ft_get_clean_line(char *str, char delim);
char	**ft_alloc_tab(char *str, char c);
char	**ft_strsplit(const char *str, char c);

/*
** ft_builtin_utility.c
*/
int		ft_is_builtin(char *name);
t_env	*ft_builtin(char **argv, t_env *env);
t_env	*ft_builtin_env(t_env *env);

/*
**	ft_0_free.c
*/
void	ft_free_argv(char **argv);

#endif
