/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:24:06 by siykim            #+#    #+#             */
/*   Updated: 2022/09/07 15:46:10 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printer(t_stack *stack)
{
	printf("a : ");
	for(int i = 0; i <= stack->a_top; i++)
	{
		printf("%d ", stack->a[i]);
	}
	printf("TOP\n");
	printf("b : ");
	for(int i = 0; i <= stack->b_top; i++)
	{
		printf("%d ", stack->b[i]);
	}
	printf("TOP\n");
}

int	main(int argc, char **argv)
{
	t_stack stack;

	init_stack(argc, argv, &stack);
	sort_main(&stack);

	printer(&stack);




/*
	printer(&stack);
	printf("\nswap a\n\n");
	swap_a(&stack);
	printer(&stack);
	printf("\npush b\n\n");
	push_b(&stack);
	printer(&stack);
	printf("\nrotate a\n\n");
	rotate_a(&stack);
	printer(&stack);
	printf("\nreverse rotate a\n\n");
	reverse_rotate_a(&stack);
	printer(&stack);
	printf("\npush a\n\n");
	push_a(&stack);
	printer(&stack);
*/

	return (0);
}