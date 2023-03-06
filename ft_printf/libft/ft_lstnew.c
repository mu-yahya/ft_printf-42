#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tx;

	tx = (t_list *)malloc(sizeof (t_list));
	if (tx != 0)
	{
		tx->content = content;
		tx->next = NULL;
	}
	return (tx);
}
