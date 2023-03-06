#include "libft.h"

char	*ft_itoa(int n)
{
	char				*c;
	int					i;
	unsigned int		z;

	z = (n < 0) * -1 * n + (n >= 0) * n;
	i = 0;
	while (z != 0)
		z = z / 10 + (0 * (++i));
	if (n <= 0)
		++i;
	c = (char *) malloc(++i);
	if (c == NULL)
		return (NULL);
	c[(--i)] = 0;
	if (n <= 0)
		c[0] = (0 - 3 * (n < 0)) + 48;
	z = -2 * (n < 0) * n + n;
	while (z != 0)
	{
		c[--i] = (2 * (z > 0) - 1) * z % 10 + 48;
		z /= 10;
	}
	return (c);
}
