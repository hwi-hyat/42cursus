#include"libft_bonus.h"

int ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	if (lst == NULL)
		return (0);
	i = 0;
	temp = lst;
	while(temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
