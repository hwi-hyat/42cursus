#include"libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int	len;

	len = ft_lstsize(lst[0]);
	if (len == 0)
		return;
	len -= 1;
	while (len >= 0)
	{
		del(lst[len]);
		free(lst[len]->next);
		//free(lst[len]);
		len--;
	}
	free (lst);
	lst = NULL;
}