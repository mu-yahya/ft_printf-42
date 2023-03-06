#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	int				z;

	if (n <= 0)
		return (NULL);
	z = (int) n;
	a = (unsigned char *) s;
	c = (c + 256) % 256;
	while (--z >= 0 && *a != c)
	{
		++a;
		++s;
	}
	if (z < 0)
		return (NULL);
	return ((void *)(a));
}
