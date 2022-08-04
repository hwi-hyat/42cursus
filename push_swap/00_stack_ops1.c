/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_stack_ops1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 01:15:44 by siykim            #+#    #+#             */
/*   Updated: 2022/08/03 17:18:39 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (stack->a_top < 1)
		return ;
	tmp = stack->a[stack->a_top];
	stack->a[stack->a_top] = stack->a[stack->a_top - 1];
	stack->a[stack->a_top - 1] = tmp;
}

void	swap_b(t_stack *stack)
{
	int	tmp;

	if (stack->b_top < 1)
		return ;
	tmp = stack->b[stack->b_top];
	stack->b[stack->b_top] = stack->b[stack->b_top - 1];
	stack->b[stack->b_top - 1] = tmp;
}

void	push_a(t_stack *stack)
{
	if (stack->b_top == -1)
		return ;
	stack->a[++stack->a_top] = stack->b[stack->b_top - 1];
	stack->b_top--;
}

void	push_b(t_stack *stack)
{
	if (stack->a_top == -1)
		return ;
	stack->b[++stack->b_top] = stack->a[stack->a_top - 1];
	stack->a_top--;
}
