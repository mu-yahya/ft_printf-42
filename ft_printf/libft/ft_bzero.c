#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*x;
	int		a;

	x = (char *) s;
	a = 0;
	while (++a <= (int) n)
	{
		*x = 0;
		++x;
	}
}
