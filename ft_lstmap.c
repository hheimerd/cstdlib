
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	if (!(first = ft_lstnew(f(lst->content))))
		return (NULL);
	current = first;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		if (!current->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (first);
}
