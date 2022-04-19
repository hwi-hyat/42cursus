/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:31:41 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:31:41 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_temp;

	lst_temp = lst;
	while (lst_temp)
	{
		f(lst_temp->content);
		lst_temp = lst_temp->next;
	}
}
