#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	c = c % 256;
	a = (char *) s;
	while (*a != c && *a != 0)
		++a;
	if (*a == 0 && c != 0)
		a = 0;
	return (a);
}
