#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	x;
	int	o;

	x = 0;
	o = ft_strlen(src);
	if (size == 0)
		return (o);
	while (((int) size < 0 || ++x < (int) size) && *src != 0)
	{
		*dst = *src;
		++src;
		++dst;
	}
	*dst = 0;
	return (o);
}
