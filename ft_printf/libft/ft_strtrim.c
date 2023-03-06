#include "libft.h"

static int	checker(char const s1, char const *set)
{
	int	j;

	j = -1;
	while (++j != -3 && s1 != set[j] && set[j] != 0)
		;
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (NULL);
	i = -1;
	j = 0;
	k = 0;
	while (set[j] != 0 && s1[++i] != 0)
		j = checker(s1[i], set);
	i = (i >= 0) * i;
	j = i - 1;
	if (s1[i] != 0)
	{
		while (s1[++j] != 0)
			;
		while (set[k] != 0 && --j >= 0)
			k = checker(s1[j], set);
	}
	s = ft_substr(s1, i, j - i + 1);
	if (s == 0)
		return (NULL);
	return (s);
}
