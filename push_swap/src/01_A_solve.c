/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_A_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:34:42 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/17 17:50:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	func_a_to_b(t_arr *a, t_arr *b, int *idx)
{
	p_b(a, b);
	r_b(b);
	*idx += 1;
}

void	a_to_b(t_arr *a, t_arr *b, int r, int magic)
{
	int	*sorted;
	int	idx;

	if (a->len == 0)
		return ;
	sorted = set_pivot(a, a->len);
	idx = 0;
	while (r-- > 0)
	{
		if (a->rst[a->len - 1] <= sorted[idx])
		{
			p_b(a, b);
			idx++;
		}
		else if (a->rst[a->len - 1] > sorted[idx]
			&& a->rst[a->len - 1] <= sorted[idx + magic])
			func_a_to_b(a, b, &idx);
		else
			r_a(a);
	}
	free(sorted);
	a_to_b(a, b, a->len, magic);
}

int	search_idx(t_arr *b, int n)
{
	int	i;

	i = 0;
	while (i < b->len)
	{
		if (b->rst[i] == n)
			break ;
		i++;
	}
	if ((i + 1) > b->len / 2)
		return (1);
	else
		return (2);
}

void	b_to_a(t_arr *a, t_arr *b)
{
	int	*sorted;
	int	tmp;

	if (b->len == 0)
		return ;
	sorted = set_pivot(b, b->len);
	tmp = search_idx(b, sorted[b->len - 1]);
	if (tmp == 1)
	{
		while (b->rst[b->len - 1] != sorted[b->len - 1])
			r_b(b);
	}
	else
	{
		while (b->rst[b->len - 1] != sorted[b->len - 1])
		{
			rr_b(b);
			write(1, "rrb\n", 4);
		}
	}
	p_a(a, b);
	free(sorted);
	b_to_a(a, b);
}

void	solve(t_arr *a, t_arr *b, int r)
{
	int	magic;

	if (r == 2)
		two_random_case(a);
	else if (r == 3)
		three_random_case(a);
	else if (r == 5)
		five_random_case(a, b);
	else
	{
		if (r == 100)
			magic = 15;
		else if (r == 500)
			magic = 30;
		else
			magic = 20;
		a_to_b(a, b, a->len, magic);
		b_to_a(a, b);
	}
}
