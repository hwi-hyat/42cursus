/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:14:00 by siykim            #+#    #+#             */
/*   Updated: 2022/05/03 01:33:37 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int check(const char c, va_list ap)
{
	if (c == 'c')
		return (type_c(ap));
	//else if (c == 's')
	//	return (type_s(ap));
	else if (c == 'p')
		return (type_p(ap));
	else if (c == 'd' || c == 'i')
		return (type_di(ap));
	else if (c == 'u')
		return (type_u(ap));
	/*else if (c == 'x')
		return (type_x(ap));
	else if (c == 'X')
		return (type_X(ap));
	else if (c == '%')
		return (type_percent());*/
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int	cnt;

	va_list ap;
	va_start(ap, str);
	cnt = 0;
	while (*(str) != 0)
	{
		if (*str == '%')
		{
			cnt += check(*(str + 1), ap);
			str += 2;
		}
		else
		{
			write(1, str, 1);
			cnt++;
			str++;
		}
	}
	return (cnt);
}

#include<stdio.h>
int main()
{
	char c = 'c';
	int ret;
	ret = ft_printf("char %c\n", c);
	printf("%d\n\n\n", ret);




	ret = ft_printf("ft_printf %p\n", &c);
	printf("   printf %p\n", &c);
	printf("%d\n\n\n", ret);


	int n = -123;
	ret = ft_printf("ft_printf %d\n", n);
	printf("   printf %d\n", n);
	printf("%d\n\n\n", ret);


	return 0;
}
