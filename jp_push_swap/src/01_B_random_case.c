/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:41:22 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 21:24:31 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_random_case(t_arr *a)
{
	if (a->rst[a->len - 1] > a->rst[a->len - 2])
	{
		swap_a(a);
		write(1, "sa\n", 3);
	}
}

void	three_random_case(t_arr *arr)
{
	t_arr	tmp;

	tmp.rst = (int *)malloc(arr->len * sizeof(int));
	if (tmp.rst == NULL)
		return ;
	copy_arr(arr, &tmp);
	if (case_one(&tmp, arr) == 1)
		return (free(tmp.rst));
	else if (case_two(&tmp, arr) == 1)
		return (free(tmp.rst));
	else if (case_three(&tmp, arr) == 1)
		return (free(tmp.rst));
	else if (case_four(&tmp, arr) == 1)
		return (free(tmp.rst));
	else if (case_five(&tmp, arr) == 1)
		return (free(tmp.rst));
	free(tmp.rst);
}
