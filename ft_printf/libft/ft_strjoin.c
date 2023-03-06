#include "libft.h"

static char	*ft_strjoin_f(char const *s1, char const *s2)
{
	char const	*x;
	char const	*y;
	char		*c;
	char		*send;
	int			z;

	x = s1;
	y = s2;
	z = 1;
	while (*s1 != 0 && ++z >= 0)
		++s1;
	while (*s2 != 0 && ++z >= 0)
		++s2;
	send = (char *) malloc(z);
	if (!send)
		return (send);
	c = send;
	while (z > 0)
	{
		if (--z && *x == 0)
			*(c++) = *(y++);
		else
			*(c++) = *(x++);
	}
	return (send);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;

	if (!s1 || !s2)
		return (0);
	x = ft_strjoin_f(s1, s2);
	return (x);
}
