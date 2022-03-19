#include"libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list *out;

	out = (t_list *)malloc(sizeof(t_list));
	if (out == 0)
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}