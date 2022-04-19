/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:31:27 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:31:27 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int	len;

	len = ft_lstsize(lst[0]);
	if (len == 0)
	{
		lst[0] = new;
		return ;
	}
	lst[len - 1]->next = new;
}
