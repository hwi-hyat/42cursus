/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:20:07 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 21:15:27 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	my_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static long long	get_result(char *str, int i, long long result, int neg)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = str[i] - '0' + result * 10;
		i++;
	}
	return (result * neg);
}

long long	ft_atoi(const char *nptr)
{
	char		*str;
	int			neg;
	int			cnt;
	int			i;
	long long	result;

	str = (char *)nptr;
	neg = 1;
	cnt = 0;
	result = 0;
	i = 0;
	while (my_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		cnt++;
		if (cnt > 1)
			return (0);
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (get_result(str, i, result, neg));
}
