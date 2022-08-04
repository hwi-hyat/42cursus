/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 00:31:24 by siykim            #+#    #+#             */
/*   Updated: 2022/08/03 17:30:18 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_check(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while(i < stack->numbers)
	{
		j = i + 1;
		while(j < stack->numbers)
		{
			if(stack->a[i] == stack->a[j])
				error(stack);
			j++;
		}
		i++;
	}
}

void	fill_stack(char **argv, t_stack *stack)
{
	int	i;
	
	i = 0;
	while(i < stack->numbers)
	{
		stack->a[i] = a_to_i(argv[stack->numbers - i], stack);
		i++;
	}
	stack->a_top = stack->numbers - 1;
	stack->b_top = -1;
	repeat_check(stack);
}

void	init_stack(int argc, t_stack *stack)
{		
	stack->numbers = argc - 1;
	stack->a = (int *)malloc(sizeof(int) * stack->numbers);
	if (stack->a == NULL)
		error(stack);
	stack->b = (int *)malloc(sizeof(int) * stack->numbers);
	if (stack->b == NULL)
		error(stack);
}

void liberate_stack(t_stack *stack)
{
	if (stack->a != NULL)
		free(stack->a);
	if (stack->b != NULL)
		free(stack->b);
}
