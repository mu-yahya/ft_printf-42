#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*x;
	char	*y;
	int		z;
	int		q;

	if (dst == src)
		return (dst);
	x = (char *) dst;
	y = (char *) src;
	z = -1 * (y >= x) + len * (x > y);
	q = -1 * (z > 0) + 1 * (z < 0);
	z = z + q;
	while (z != (int)len && z != -1)
	{
		x[z] = y[z];
		z = z + q;
	}
	return (dst);
}
