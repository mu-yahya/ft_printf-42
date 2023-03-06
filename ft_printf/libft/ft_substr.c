#include "libft.h"

static char	*ft_substr_f(char const *s, unsigned int start, size_t len)
{
	char	*c;
	char	*l;
	int		i;

	i = ft_strlen(s);
	len = ((int) i > (int) start) * len;
	if (len != 0 && (int) start + (int) len > i)
		len = (size_t) i - (size_t) start;
	c = (char *) malloc (len + 1);
	if (c)
	{
		l = c;
		i = 0;
		s = s + start;
		while (i < (int) len && *s != 0 && ++i)
		{
			*c = *s;
			++c;
			++s;
		}
		*c = 0;
		return (l);
	}
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;

	if (!s)
		return (NULL);
	x = ft_substr_f(s, start, len);
	return (x);
}
