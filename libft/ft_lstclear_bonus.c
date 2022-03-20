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
		ft_lstdelone(lst[len], del);
		len--;
	}
}