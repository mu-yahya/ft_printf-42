#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dst;
	int		z;

	dst = (char *) b;
	z = len;
	while (--z >= 0)
	{
		*dst = c;
		++dst;
	}
	return (b);
}
