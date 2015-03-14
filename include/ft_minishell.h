/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:34:46 by mgras             #+#    #+#             */
/*   Updated: 2015/03/14 18:29:04 by tlebrize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL
# define FT_MINISHELL
# define BUF_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <signal.h>
# include <limits.h>

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_pth
{
	char			*path;
	struct s_pth	*next;
}					t_pth;

/*
**	ft_core.c
*/
char	**ft_fill_envp_clone(char **clone, char **origin);
void	ft_prompt(char **envp, t_env *env);

/*
**	ft_get_next_line.c
*/
char	*ft_fill_holder(int fd);
int		ft_get_next_line(int fd, char **line);

/*
**	ft_env.c
*/
char	**ft_get_envp(t_env *env);
t_env	*ft_new_env(t_env *env, char *full);
t_env	*ft_get_env(t_env *env, char **envp);
t_env	*ft_free_member(t_env *current, t_env *saved);

/*
**	ft_check_argv.c
*/
int		ft_check_setenv(char *arg);

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
char	*ft_strcat(char *s1, char *s2);

/*
**	ft_2_utility.c (Strsplit)
*/
char	**ft_strsplit(char *str, char c);

/*
** ft_builtin_utility.c
*/
int		ft_is_builtin(char *name);
t_env	*ft_builtin(char **argv, t_env *env);
t_env	*ft_builtin_env(t_env *env);

/*
**	ft_builtin_fnc.c
*/
t_env	*ft_maj_pwd(t_env *env);
t_env	*ft_oldpwd(t_env *env);
t_env	*ft_setenv(t_env *env, char *mod);
t_env	*ft_unsetenv(t_env *env, char *mod);
t_env	*ft_cd(t_env *env, char *dir);

/*
**	ft_builtin_gmb.c
*/
void	ft_cd_errors(int index, char *erred);
t_env	*ft_home_cd(t_env *env);


/*
** ft_new_process.c
*/
char	*ft_split_path(char *value);
void	ft_new_process(char *path, char **argv, t_env *env);
char	*ft_find_bin(char *bin, t_env *env);
t_pth	*ft_new_pth(t_pth *pth, char *path);
t_pth	*ft_get_pth(t_pth *pth, t_env *env);

/*
**	ft_0_free.c
*/
void	ft_free_argv(char **argv);

/*
**	0_error.c
*/
void	e_no_match_env(char *erred_str);
void	e_no_such_path(char *erred_str);

#endif
