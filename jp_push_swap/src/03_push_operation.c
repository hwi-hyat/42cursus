/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:08:12 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 20:42:55 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_arr *a, t_arr *b)
{
	if (b->len == 0)
		return ;
	a->rst[a->len] = b->rst[b->len - 1];
	b->rst[b->len - 1] = 0;
	a->len += 1;
	b->len -= 1;
}

void	push_b(t_arr *a, t_arr *b)
{
	if (a->len == 0)
		return ;
	b->rst[b->len] = a->rst[a->len - 1];
	a->rst[a->len - 1] = 0;
	a->len -= 1;
	b->len += 1;
}
