#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	l;

	if (!fd || !s)
		return ;
	l = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &l, 1);
}
