/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:14:00 by siykim            #+#    #+#             */
/*   Updated: 2022/07/24 21:26:38 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minitalk.h"

int	check(const char c, va_list *ap)
{
	if (c == 'd')
		return (type_di(ap));
	else if (c == 's')
		return (type_s(ap));
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	ap;

	va_start(ap, str);
	cnt = 0;
	while (*(str) != 0)
	{
		if (*str == '%')
		{
			cnt += check(*(str + 1), &ap);
			str += 2;
		}
		else
		{
			write(1, str, 1);
			cnt++;
			str++;
		}
	}
	va_end(ap);
	return (cnt);
}
