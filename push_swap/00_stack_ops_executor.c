/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_stack_ops_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:49:48 by siykim            #+#    #+#             */
/*   Updated: 2022/09/07 16:29:54 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	exe_r(char *op, t_stack *stack)
{
	if (!ft_strncmp(op, "ra", 3))
		rotate_a(stack);
	else if (!ft_strncmp(op, "rb", 3))
		rotate_b(stack);
	else if (!ft_strncmp(op, "rr", 3))
	{
		rotate_a(stack);
		rotate_b(stack);
	}
	else if (!ft_strncmp(op, "rra", 3))
		reverse_rotate_a(stack);
	else if (!ft_strncmp(op, "rrb", 3))
		reverse_rotate_b(stack);
	else if (!ft_strncmp(op, "rrr", 3))
	{
		reverse_rotate_a(stack);
		reverse_rotate_b(stack);
	}
}

void	exe(char *op, t_stack *stack)
{
	if (!ft_strncmp(op, "sa", 3))
		swap_a(stack);
	else if (!ft_strncmp(op, "sb", 3))
		swap_b(stack);
	else if (!ft_strncmp(op, "ss", 3))
	{
		swap_a(stack);
		swap_b(stack);
	}
	else if (!ft_strncmp(op, "pa", 3))
		push_a(stack);
	else if (!ft_strncmp(op, "pb", 3))
		push_b(stack);
	else if (op[0] == 'r')
		exe_r(op, stack);
	
	write(1, op, str_len(op));
	write(1, "\n", 1);
}