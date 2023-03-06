#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s) + 1;
	c = c % 256;
	while (--a >= 0 && s[a] != c)
		;
	if (a < 0)
		s = NULL;
	else
		s = s + a;
	return ((char *) s);
}
