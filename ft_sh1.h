
#ifndef FT_SH1_H
# define FT_SH1_H
# include <unistd.h>
# include <stdlib.h>

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
int		ft_intlen(int n);
void	ft_putnbr(int n);
void	ft_bzero(char *str, size_t size);

