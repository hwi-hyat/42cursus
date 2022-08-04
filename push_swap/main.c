/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:24:06 by siykim            #+#    #+#             */
/*   Updated: 2022/08/03 21:51:56 by siykim           ###   ########.fr       */
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
	printf("\n");
	printf("b : ");
	for(int i = 0; i <= stack->b_top; i++)
	{
		printf("%d ", stack->b[i]);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack stack;

	init_stack(argc, &stack);
	fill_stack(argv, &stack);
	sort_main(&stack);

	printer(&stack);
	swap_a(&stack);
	printf("\nswapped a\n\n");
	printer(&stack);


	return (0);
}