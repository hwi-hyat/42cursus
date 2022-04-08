#include"libft_bonus.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	while(*lst)
	{
		ft_lstdelone((*lst), del);
		*lst = (*lst)->next;
	}
}
