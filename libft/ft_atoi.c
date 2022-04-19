/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:30:14 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:30:14 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	out;

	i = 0;
	neg = 1;
	out = 0;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		out *= 10;
		out += nptr[i] - '0';
		i++;
	}
	return (neg * out);
}
