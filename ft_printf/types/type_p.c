/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:13:58 by siykim            #+#    #+#             */
/*   Updated: 2022/05/11 13:54:56 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

void	put_nbr_p(unsigned long long n, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "0x", 2);
		(*len) += 2;
		return ;
	}
	else
	{
		put_nbr_p(n / 16, len);
		write(1, &hex[(n % 16)], 1);
		(*len)++;
	}
	return ;
}

int	type_p(va_list *ap)
{
	int					len;
	unsigned long long	out;

	len = 0;
	out = (unsigned long long)va_arg(*ap, void *);
	if (out == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	put_nbr_p(out, &len);
	return (len);
}
