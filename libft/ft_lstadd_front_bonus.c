#include"libft_bonus.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	lst[0]->content = new;
}