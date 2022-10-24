/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:34:54 by siykim            #+#    #+#             */
/*   Updated: 2022/09/07 20:29:16 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	set_pivot(int *stack, int start, int end)
{
	int	mid = (start + end) / 2;
	int	nums[3];

	nums[0] = stack[start];
	nums[1] = stack[mid];
	nums[2] = stack[end];
	printf("making pivot %d %d %d\n", nums[0], nums[1], nums[2]);
	if (nums[0] > nums[1])
		swap(&nums[0], &nums[1]);
	if (nums[1] > nums[2])
		swap(&nums[2], &nums[1]);
	if (nums[0] > nums[1])
		swap(&nums[0], &nums[1]);
	return (nums[1]);
}

void 	devide_a(t_stack *stack, int size)
{
	int	pivot;
	int	i;

	pivot = set_pivot(stack->a, 0, size - 1);
	printf("pivot is %d\n", pivot);
	i = 0;
	while(i <= size)
	{
		if (stack->a[stack->a_top] >= pivot)
			exe("pb", stack);
		else
			exe("ra", stack);
		i++;
	}
	devide_a(stack, stack->a_top + 1);
	
}

void	sort_main(t_stack *stack)
{
	devide_a(stack, stack->numbers);
}

