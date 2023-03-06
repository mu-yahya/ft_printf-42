#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ref;

	if (*lst)
	{
		ref = *lst;
		while (ref->next != NULL)
			ref = ref->next;
		ref->next = new;
	}
	else
		*lst = new;
}
