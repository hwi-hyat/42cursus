/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:13:58 by siykim            #+#    #+#             */
/*   Updated: 2022/05/11 00:28:17 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

void put_nbr_u(unsigned long long n, int *len)
{
	char out;

	if (n == 0)
		return ;
	else
	{
		out = (n % 10) + '0';
		put_nbr_u(n / 10, len);
		write(1, &out, 1);
		(*len)++;
	}
	return ;
}

unsigned int	type_u(va_list *ap)
{
	unsigned long long	out;
	int					len;

	len = 0;
	out = va_arg(*ap, unsigned int);
	if (out == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	put_nbr_u(out, &len);
	return (len);
}
