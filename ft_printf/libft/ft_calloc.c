#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (void *) malloc ((size_t)count * size);
	if (a != 0)
		ft_bzero(a, count * size);
	return (a);
}
