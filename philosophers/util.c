/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:01:45 by siykim            #+#    #+#             */
/*   Updated: 2022/11/18 15:03:37 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	a_to_i(const char *str)
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
	if (out > 2147483647 || out < -2147483648)
		return (0);
	return ((int)neg * out);
}