/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:34:46 by mgras             #+#    #+#             */
/*   Updated: 2015/03/21 19:39:30 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL
# define FT_MINISHELL
# define BUF_SIZE 42

# include "colors.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <signal.h>
# include <limits.h>
# include <time.h>

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
**	ft_cleaner.c
*/
int		ft_clean_len(char *dirty_pleb);
char	*ft_clean_str(char *dirty_pleb);

/*
**	MLP Fan club
*/
void	ft_color(char **envp);

/*
**	ft_core.c
*/
char	**ft_fill_envp_clone(char **clone, char **origin);
void	ft_prompt(char **envp, t_env *env);

void	ft_colors(char **envp);

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
t_env	*ft_maj_old(t_env *env);

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
