#include"libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int	len;

	len = ft_lstsize(lst[0]);
	if (len == 0)
	{
		lst[0] = new;
		return;
	}
	lst[len - 1]->next = new;
}