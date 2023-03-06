#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	int				z;
	int				n1;

	z = 0;
	n1 = n;
	x = (unsigned char *) s1;
	y = (unsigned char *) s2;
	while (++z <= n1)
	{
		if (*x != *y)
			return (*x - *y);
		++x;
		++y;
	}
	return (0);
}
