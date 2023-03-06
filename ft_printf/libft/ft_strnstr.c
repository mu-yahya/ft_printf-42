#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	x;
	int	n;

	if (haystack[0] == 0 && needle[0] == 0)
		return ((char *)haystack);
	n = 0;
	x = -1;
	if ((int) len < 0)
		len = ft_strlen(haystack);
	while (haystack[++x] != 0 && needle[n] != 0 && x < (int) len)
		if (haystack[x] == needle[n])
			++n;
	else
	{
		if (n > 0)
			x = x - n;
		n = 0;
	}
	if (needle[n] != 0)
		return (0);
	return ((char *)(haystack + x - n));
}
