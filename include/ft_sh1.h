/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:51:50 by mgras             #+#    #+#             */
/*   Updated: 2015/02/22 18:35:53 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

# define BUF_SIZE 42

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
** core.c
*/
int		ft_check_builtin(char **argv, t_env *env, char **envp);

/*
** ft_prompt.c
*/
void				ft_process_arg(char **argv, t_env *env, t_pth *pth, char **envp);
void				ft_prompt(char *prompt, char **envp, t_env *env, t_pth *pth);
void				ft_new_process(const char *path, char *const *argv, char *const *envp);
char				*ft_make_path(char *dest, char *path, char *file);
char				*ft_find_bin(char *bin_name, t_pth *pth, char *path);
/*
** ft_get_next_line.c
*/
char				*ft_fill_holder(int fd);
int					ft_get_next_line(int fd, char **line);
int					ft_process_line(char *holder, int h_swiper, char **line);

/*
** ft_libstr_0.c
*/
char				*ft_strdup(const char *src);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
void				ft_putchar(char c);

/*
** ft_libstr_1.c
*/
void				ft_putstr(char *str);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_intlen(int n);
void				ft_putnbr(int n);
void				ft_bzero(char *str, size_t size);

/*
** ft_libstr_2.c
*/
char	*ft_strncpy(char *dst, char *src, int len);

/*
** ft_get_argv.c
*/
char				*ft_get_clean_line(char *line, char delim, int ss);
int					ft_ssize(char *clean_line, char delim, int pos);
int					ft_tsize(char *clean_line, char delim);
char				**ft_get_argv(char *line, char d);
char				**ft_strsplit(char *line, char delim);

/*
** ft_arg_utility.c
*/
int					ft_get_argc(char *input, char delim);
void				ft_free_argv(char **argv, int argc);
int					ft_check_cmd(char *line, char *cmd);
char				*ft_get_path(char *line);
char				*ft_get_exec_path(char *cmd);

/*
** env
*/
t_env	*ft_fill_env(char **envp, t_env *env, t_env *tmp);
t_env	*ft_new_env_link(t_env *env);
int		ft_get_nam_len(char *name);
int		ft_get_va_len(char *val);
t_env	*ft_new_env_end(t_env *env, char *full, int ts, int ss);

/*
** pth
*/
t_pth	*ft_alloc_path(t_pth *pth, char *value, int *pos);
t_pth	*ft_new_pth_end(t_pth *pth, int *pos, char *value);
t_pth	*ft_fill_path(t_env *env, t_pth *pth);


/*
** ft_env_update
*/
char	*ft_daijobu(char *name, char *val);
char	**ft_yamete(t_env *env, char **envp);

/*
** Builtin
*/
int		ft_unsetenv_2(t_env *tmp, t_env *save, char *unset_name);
t_env	*ft_unsetenv(char *unset_name, t_env *env);
char	**ft_setenv(char **argv, t_env *env, char **envp);
void	ft_env(t_env *env);
int		ft_check_name(t_env *env, char *full);
#endif
