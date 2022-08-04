/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:26:10 by siykim            #+#    #+#             */
/*   Updated: 2022/08/03 17:30:16 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_to_i(const char *str, t_stack *stack)
{
	int	i;
	int	neg;
	int	out;

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
	if (str[i])
		error(stack);
	return (neg * out);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	error(t_stack *stack)
{
	liberate_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
