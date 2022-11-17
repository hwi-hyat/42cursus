/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_A_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:10:17 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/17 16:52:00 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_input(int argc, char *argv[])
{
	int	i;
	int	idx;

	i = 1;
	while (i < argc)
	{
		idx = 0;
		while (argv[i][idx])
		{
			if (!((argv[i][idx] >= '0' && argv[i][idx] <= '9')
				|| argv[i][idx] == ' ' || argv[i][0] == '-'))
				ft_errors();
			idx += 1;
		}
		i += 1;
	}
}

static void	alloc_arr(int argc, char *argv[], t_arr *arr)
{
	int	cnt;

	cnt = count_int_nums(argc, argv);
	arr->len = cnt;
	arr->rst = (int *)malloc(cnt * sizeof(int));
	if (arr->rst == NULL)
		exit(1);
}

long long	a_to_i(const char *str)
{
	int			i;
	int			neg;
	long long	out;

	i = 0;
	neg = 1;
	out = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		out *= 10;
		out += str[i++] - '0';
	}
	return ((long long)neg * out);
}

static int	str_to_int(int argc, char *argv[], t_arr *arr)
{
	int			i;
	int			j;
	long long	tmp;

	i = 1;
	j = arr->len - 1;
	while (i < argc)
	{
		tmp = a_to_i(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (0);
		arr->rst[j] = (int)tmp;
		j -= 1;
		i++;
	}
	return (1);
}

void	ft_parse(int argc, char *argv[], t_arr *arr)
{
	int	a;
	int	b;

	check_input(argc, argv);
	alloc_arr(argc, argv, arr);
	a = str_to_int(argc, argv, arr);
	b = check_repeat(arr);
	if (a == 0 || b == 0)
	{
		free(arr->rst);
		ft_errors();
	}
}
