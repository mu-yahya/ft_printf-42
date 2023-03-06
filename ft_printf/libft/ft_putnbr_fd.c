#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c[13];
	unsigned int	i;
	int				z;

	c[12] = 0;
	z = 45;
	if (fd && n < 0)
		write(fd, &z, 1);
	z = 48;
	if (fd && n == 0)
	{
		write(fd, &z, 1);
		return ;
	}
	z = 12;
	i = (n * (n > 0)) + (-1 * n * (n < 0));
	while (i > 0)
	{
		c[--z] = i % 10 + 48;
		i = i / 10;
	}
	if (fd)
		write(fd, c + z, 12 - z);
}
