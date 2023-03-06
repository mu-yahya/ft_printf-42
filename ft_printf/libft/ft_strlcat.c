#include "libft.h"

static int	len(char *dst, size_t size)
{
	int	x;

	x = -1;
	while ((++x < (int) size) && dst[x] != 0)
		;
	if (dst[x] != 0)
		x = -1;
	return (x);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	x;
	int	y;
	int	z;

	x = -1;
	if ((int)size > 0)
		y = len(dst, size);
	else
		y = ft_strlen(dst);
	if (y < 0)
		return (ft_strlen(src) + (int) size);
	z = y - 1;
	y = (int) size - y - 1;
	while ((++x < y || (int) size < 0) && src[x] != 0)
		dst[++z] = src[x];
	dst[++z] = 0;
	y = size - y - 1;
	x = (int) size;
	y = y * (x < 0 || x >= y) + size * (x > 0 && x < y) + ft_strlen(src);
	return (y);
}
