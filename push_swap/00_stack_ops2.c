/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_stack_ops2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 01:58:11 by siykim            #+#    #+#             */
/*   Updated: 2022/08/03 17:21:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;
	
	if (stack->a_top < 1)
		return ;
	i = stack->a_top;
	tmp = stack->a[i];
	while (i > 1)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
}

void	rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->b_top < 1)
		return ;
	i = stack->b_top;
	tmp = stack->b[i];
	while (i > 1)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
}

void	reverse_rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->a_top < 1)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (i < stack->a_top - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->a_top] = tmp;
}

void	reverse_rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->b_top < 1)
		return ;
	tmp = stack->b[0];
	i = 0;
	while (i < stack->b_top - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->b_top] = tmp;
}