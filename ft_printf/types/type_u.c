/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:13:58 by siykim            #+#    #+#             */
/*   Updated: 2022/05/03 01:33:09 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

void put_nbr(unsigned int n, unsigned int *len)
{
	char out;

	if (n == 0)
		return ;
	else
	{
		out = (n % 10) + '0';
		put_nbr(n / 10, len);
		write(1, &out, 1);
		(*len)++;
	}
	return ;
}

unsigned int	type_u(va_list ap)
{
	unsigned int	out;
	unsigned int	len;

	len = 0;
	out = va_arg(ap, unsigned int);
	put_nbr(out, &len);
	return (len);
}
