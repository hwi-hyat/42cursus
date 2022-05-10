/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_XX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:13:58 by siykim            #+#    #+#             */
/*   Updated: 2022/05/11 00:27:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

void put_nbr_X(unsigned int n, int *len)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n == 0)
		return ;
	else
	{
		put_nbr_X(n / 16, len);
		write(1, &hex[(n % 16)], 1);
		(*len)++;
	}
	return ;
}

int	type_X(va_list *ap)
{
	int				len;
	unsigned int	out;

	len = 0;
	out = va_arg(*ap, unsigned int);
	if (out == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	put_nbr_X(out, &len);
	return (len);
}
