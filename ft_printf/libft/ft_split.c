#include "libft.h"

static char	**alloc_2d(int x)
{
	char	**ii;

	ii = (char **)malloc((x * sizeof(char *)));
	return (ii);
}

static int	wc(char const *s, char c)
{
	int	i;
	int	j;

	if (s[0] == 0)
		return (0);
	if (c == 0)
		return (1);
	i = -1;
	j = 0;
	while (s[++i] != 0)
		if (((i >= 1 && s[i - 1] != c) || i == 0) && s[i] == c)
			++j;
	if (s[0] != c && s[0] != 0)
		++j;
	if (s[i - 1] == c)
		--j;
	return (j);
}

static char	*sub(const char *s, int start, int len)
{
	char	*c;
	int		i;

	c = (char *) malloc ((size_t)(len + 1));
	if (c)
	{
		i = -1;
		while (++i < len && *s != 0)
			c[i] = s[i + start];
		c[i] = 0;
		return (c);
	}
	else
		return (0);
}

static char	**ft_split_f(char const *s, char c)
{
	int		k;
	int		i;
	char	**pt;
	int		z;
	char	**o;

	pt = alloc_2d(wc(s, c) + 1);
	o = pt;
	i = 0;
	k = 0;
	z = -1;
	while ((z < 0 || s[z] != 0) && k >= 0 && pt != 0)
	{
		if (s[++z] != c && s[z] != 0 && ++k == 1)
			i = z;
		if (k != 0 && (s[z] == 0 || s[z] == c))
		{
			*pt = sub(s, i, k);
			k = 3 * (s[z] == 0);
			++pt;
		}
	}
	if (pt != 0)
		*pt = 0;
	return (o);
}

char	**ft_split(char const *s, char c)
{
	char	**x;

	if (!s)
		return (0);
	x = ft_split_f(s, c);
	return (x);
}
