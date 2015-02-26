/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:34:46 by mgras             #+#    #+#             */
/*   Updated: 2015/02/26 16:04:16 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL
# define FT_MINISHELL

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
int		ft_strlen(char *str);
int		ft_tablen(char **tab);
char	*ft_strcpy(char *dst, char *src);

/*
**	ft_1_utility.c
*/
char	*ft_strncpy(char *dst, char *src, size_t n);

#endif