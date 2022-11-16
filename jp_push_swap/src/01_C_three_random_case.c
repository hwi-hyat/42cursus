/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:35:56 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 21:17:51 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case_one(t_arr *a, t_arr *arr)
{
	swap_a(a);
	if (is_already_sorted(a) == 1)
	{
		swap_a(arr);
		write (1, "sa\n", 3);
		return (1);
	}
	swap_a(a);
	return (0);
}

int	case_two(t_arr *a, t_arr *arr)
{
	swap_a(a);
	rr_a(a);
	if (is_already_sorted(a) == 1)
	{
		swap_a(arr);
		rr_a(arr);
		write (1, "sa\n", 3);
		write (1, "rra\n", 4);
		return (1);
	}
	rotate_a(a);
	swap_a(a);
	return (0);
}

int	case_three(t_arr *a, t_arr *arr)
{
	rotate_a(a);
	if (is_already_sorted(a) == 1)
	{
		rotate_a(arr);
		write (1, "ra\n", 3);
		return (1);
	}
	rr_a(a);
	return (0);
}

int	case_four(t_arr *a, t_arr *arr)
{
	swap_a(a);
	rotate_a(a);
	if (is_already_sorted(a) == 1)
	{
		swap_a(arr);
		rotate_a(arr);
		write (1, "sa\n", 3);
		write (1, "ra\n", 3);
		return (1);
	}
	rr_a(a);
	swap_a(a);
	return (0);
}

int	case_five(t_arr *a, t_arr *arr)
{
	rr_a(a);
	if (is_already_sorted(a) == 1)
	{
		rr_a(arr);
		write (1, "rra\n", 4);
		return (1);
	}
	rotate_a(a);
	return (0);
}
