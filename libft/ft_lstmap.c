/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:31:45 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:31:45 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*out_tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	out = NULL;
	while (lst)
	{
		out_tmp = ft_lstnew(f(lst->content));
		if (out_tmp == NULL)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_lstadd_back(&out, out_tmp);
		out_tmp = out_tmp->next;
		lst = lst->next;
	}
	return (out);
}
