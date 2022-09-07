/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:24:50 by siykim            #+#    #+#             */
/*   Updated: 2022/09/07 16:29:55 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h> // 나중에 지워주자

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	a_top;
	int	b_top;
	int	numbers;
}	t_stack;

//00_stack
void	init_stack(int argc, char **argv, t_stack *stack);
void 	liberate_stack(t_stack *stack);
void	fill_stack(char **argv, t_stack *stack);

//00_stack_ops1
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

//00_stack_ops2
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);

//00_stack_ops_executor
void	exe(char *op, t_stack *stack);
void	exe_r(char *op, t_stack *stack);


//01_sort
void	sort_main(t_stack *stack);


//utilities
int		a_to_i(const char *str, t_stack *stack);
int		str_len(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error(t_stack *stack);


#endif