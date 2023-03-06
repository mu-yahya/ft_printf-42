#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	++n;
	while (--n != 0 && (*s1 != 0 || *s2 != 0))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		++s1;
		++s2;
	}
	return (0);
}
