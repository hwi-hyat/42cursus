/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:58:15 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 21:23:40 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_already_sorted(t_arr *arr)
{
	int	idx;

	idx = 0;
	while (idx < arr->len - 1)
	{
		if (arr->rst[idx] < arr->rst[idx + 1])
			return (0);
		idx += 1;
	}
	return (1);
}

void	copy_arr(t_arr *src, t_arr *target)
{
	int	i;

	i = 0;
	target->len = src->len;
	while (i < src->len)
	{
		target->rst[i] = src->rst[i];
		i += 1;
	}
}

int	main(int argc, char *argv[])
{
	t_arr	a;
	t_arr	b;

	a.len = 0;
	b.len = 0;
	if (argc < 2)
		return (0);
	ft_parse(argc, argv, &a);
	b.rst = (int *)malloc(a.len * sizeof(int));
	if (is_already_sorted(&a) == 1 || b.rst == NULL)
	{
		free(a.rst);
		if (b.rst != NULL)
			free(b.rst);
		return (0);
	}
	else
		solve(&a, &b, a.len);
	free(a.rst);
	free(b.rst);
	return (0);
}
