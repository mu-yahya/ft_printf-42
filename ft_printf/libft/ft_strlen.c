#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	z;

	z = -1;
	while (s[++z] != 0)
		;
	return (z);
}
