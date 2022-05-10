/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:13:58 by siykim            #+#    #+#             */
/*   Updated: 2022/05/11 00:26:30 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

void put_nbr_di(int n, int *len)
{
	char out;

	if (n == 0)
		return ;
	else if (n < 0)
	{
		if (-10 < n)
		{
			write(1, "-", 1);
			(*len)++;
		}
		out = -(n % 10) + '0';
		put_nbr_di(n / 10, len);
		write(1, &out, 1);
		(*len)++;
	}
	else
	{
		out = (n % 10) + '0';
		put_nbr_di(n / 10, len);
		write(1, &out, 1);
		(*len)++;
	}
	return ;
}

int	type_di(va_list *ap)
{
	int	out;
	int	len;

	len = 0;
	out = va_arg(*ap, int);
	if (out == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	put_nbr_di(out, &len);
	return (len);
}
