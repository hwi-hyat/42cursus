/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:13:58 by siykim            #+#    #+#             */
/*   Updated: 2022/05/03 00:58:24 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

void	hexadecimal_out(void *addr, int *len)
{
	unsigned long long	i_addr;
	char				out[17];
	char				*hex;
	int					i;

	out[16] = 0;
	i = 15;
	hex = "0123456789abcdef";
	i_addr = (unsigned long long)addr;
	while (i_addr != 0)
	{
		out[i] = hex[i_addr % 16];
		i_addr /= 16;
		i--;
		(*len)++;
	}
	write(1, "0x", 2);
	write(1, &out[i], *len + 1);	//왜 len + 1 이지????? 내가 해놓고도 모르겠네
	(*len) += 2;
}

int	type_p(va_list ap)
{
	int		len;
	void	*out;

	len = 0;
	out = va_arg(ap, void *);
	hexadecimal_out(out, &len);
	return (len);
}
