#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*x;
	t_list	*tmp;
	t_list	*f2;

	x = NULL;
	tmp = NULL;
	while (lst != NULL)
	{
		if (x != NULL)
			tmp = x;
		x = NULL;
		x = ft_lstnew((*f)(lst->content));
		if (!x)
			ft_lstdelone(x, del);
		if (x && tmp == NULL)
			f2 = x;
		lst = lst->next;
		if (x && tmp != NULL)
			tmp->next = x;
	}
	return (f2);
}
