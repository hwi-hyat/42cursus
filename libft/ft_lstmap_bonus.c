#include"libft_bonus.h"

void lst_dup(t_list *lst, t_list **out, void (*del)(void *))
{
	int	len;
	int	i;

	len = ft_lstsize(lst);
	out = (t_list **)malloc(sizeof(t_list *) * len);
	if (out == NULL)
		return;
	i = 0;
	while (i < len)
	{
		out[i] = (t_list *)malloc(sizeof(t_list));
		if (out[i] == NULL)
		{
			ft_lstclear(out, del);
			return;
		}
		out[i]->content = lst->content;
		out[i]->next = lst->next;
		lst = lst->next;
		i++;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**out;
	
	out = NULL;
	lst_dup(lst, out, del);
	//ft_lstiter(*out, *f);
	void *fp = f;
	(void)fp;
	return (out[0]);
}