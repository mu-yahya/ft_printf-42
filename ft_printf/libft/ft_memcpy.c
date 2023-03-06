#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		x;
	char	*char_dst;
	char	*char_src;

	if (src == dst)
		return (dst);
	char_dst = (char *) dst;
	char_src = (char *) src;
	x = -1;
	while (++x < (int) n)
		char_dst[x] = char_src[x];
	return (dst);
}
