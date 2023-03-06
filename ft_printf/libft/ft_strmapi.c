#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				x;
	char			*o;

	if (!s || !f)
		return (NULL);
	x = -1;
	while (s[++x] != 0)
		;
	o = (char *)malloc(x + 1);
	if (o == 0)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		o[i] = f(i, s[i]);
		i = i + 1;
	}
	o[i] = 0;
	return (o);
}
