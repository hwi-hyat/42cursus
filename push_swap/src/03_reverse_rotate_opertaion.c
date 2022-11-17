/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_opertaion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:30:32 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 20:42:55 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr_a(t_arr *a)
{
	int	tmp;
	int	i;

	tmp = a->rst[0];
	i = 1;
	while (i < a->len)
	{
		a->rst[i - 1] = a->rst[i];
		i += 1;
	}
	a->rst[a->len - 1] = tmp;
}

void	rr_b(t_arr *b)
{
	int	tmp;
	int	i;

	tmp = b->rst[0];
	i = 1;
	while (i < b->len)
	{
		b->rst[i - 1] = b->rst[i];
		i += 1;
	}
	b->rst[b->len - 1] = tmp;
}

void	rr_rr(t_arr *a, t_arr *b)
{
	rr_a(a);
	rr_b(b);
}
