#include"libft_bonus.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = lst[0];
	lst[0] = new;
}
