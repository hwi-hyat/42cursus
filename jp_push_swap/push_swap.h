/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:24:15 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/17 01:17:41 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_arr
{
	int	*rst;
	int	len;
}	t_arr;

void		ft_parse(int argc, char *argv[], t_arr *arr);
void		solve(t_arr *a, t_arr *b, int r);


int			case_one(t_arr *a, t_arr *arr);
int			case_two(t_arr *a, t_arr *arr);
int			case_three(t_arr *a, t_arr *arr);
int			case_four(t_arr *a, t_arr *arr);
int			case_five(t_arr *a, t_arr *arr);
void		copy_arr(t_arr *src, t_arr *target);

int			is_already_sorted(t_arr *arr);
int			cnt_word(char *str, char set);

void		ft_errors(void);
void		free_alloc(char **str);
char		**ft_split(char const *s, char c);
int			count_int_nums(int argc, char *argv[]);
int			check_repeat(t_arr *arr);
int			ft_nullexeption(char **voca);

int			*set_pivot(t_arr *arr, int r);
void		three_random_case(t_arr *arr);
void		five_random_case(t_arr *a, t_arr *b);
void		two_random_case(t_arr *a);
void		p_a(t_arr *a, t_arr *b);
void		p_b(t_arr *a, t_arr *b);
void		r_a(t_arr *a);
void		r_b(t_arr *b);

void		swap_a(t_arr *a);
void		swap_b(t_arr *b);
void		swap_s(t_arr *a, t_arr *b);
void		push_a(t_arr *a, t_arr *b);
void		push_b(t_arr *a, t_arr *b);
void		rr_a(t_arr *a);
void		rr_b(t_arr *b);
void		rr_rr(t_arr *a, t_arr *b);
void		rotate_a(t_arr *a);
void		rotate_b(t_arr *b);
void		rotate_rr(t_arr *a, t_arr *b);


void		copy_arr(t_arr *src, t_arr *target);
void		three_random_case(t_arr *arr);
void		quick_sort(int *data, int start, int end);
void		r_a(t_arr *a);
void		r_b(t_arr *b);
void		p_a(t_arr *a, t_arr *b);
void		p_b(t_arr *a, t_arr *b);

#endif