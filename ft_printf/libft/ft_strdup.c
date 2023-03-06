#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*x;
	int		o;

	o = ft_strlen(s1);
	x = (char *) malloc (o + 1);
	if (x == 0)
		return (NULL);
	x[o] = 0;
	while (--o >= 0)
		x[o] = s1[o];
	return (x);
}
