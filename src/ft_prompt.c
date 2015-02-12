
#include "ft_sh1.h"

void	ft_prompt(char *prompt)
{
	char	*buff;
	int		i;

	if (!(buff = (char*)malloc(sizeof(char) * 1024)))
		return ;
	ft_bzero(buff, 1024);
	while (0 != ft_strcmp("exit\n", buff))
	{
		ft_putstr(prompt);
		i = read(0, (char*)buff, 1024);
		buff[i] = '\0';
		ft_putstr(buff);
	}
}

int		main(void)
{
	ft_prompt("4269>");
	return (0);
}
