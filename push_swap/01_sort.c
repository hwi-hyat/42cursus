/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:34:54 by siykim            #+#    #+#             */
/*   Updated: 2022/09/07 16:29:51 by siykim           ###   ########.fr       */
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

void 	devide(t_stack *stack)//, char which)
{
	//int	*current_stack;
	int	pivot;
	int	i;

	pivot = set_pivot(stack->a, 0, stack->a_top);
	printf("pivot is %d\n", pivot);
	i = 0;
	while(i <= stack->a_top)
	{
		printf("checking a_top : %d  pivot : %d  ", stack->a[stack->a_top], pivot);
		if (stack->a[stack->a_top] >= pivot)
		{
			printf("pb \n");
			exe("pb", stack);
		}
		else
		{
			printf("ra \n");
			exe("ra", stack);
		}
		i++;
	}

}

void	sort_main(t_stack *stack)
{
	devide(stack);
}

