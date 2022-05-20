/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:14:00 by siykim            #+#    #+#             */
/*   Updated: 2022/05/19 00:16:40 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	check(const char c, va_list *ap)
{
	if (c == 'c')
		return (type_c(ap));
	else if (c == 's')
		return (type_s(ap));
	else if (c == 'p')
		return (type_p(ap));
	else if (c == 'd' || c == 'i')
		return (type_di(ap));
	else if (c == 'u')
		return (type_u(ap));
	else if (c == 'x')
		return (type_x(ap));
	else if (c == 'X')
		return (type_largex(ap));
	else if (c == '%')
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
/*
int main()
{
	int ret;
	
	ret = ft_printf("ft_printf c % %c %c\n", '-', 0, '0');
	printf("   printf c %c %c %c\n", '-', 0, '0');
	printf("%d\n\n\n", ret);


	printf("ft_printf s\n");
	ret = ft_printf("%s\n", NULL);
	ret = printf("   printf\n%s\n", (char *)NULL);
	printf("%d\n\n\n", ret);


	printf("ft_printf p\n");
	ret = ft_printf("%p\n", (void *)15);
	printf("   printf\n%p\n", (void *)15);
	printf("%d\n\n\n", ret);


	int n = 9;
	ret = ft_printf("ft_printf d %d %d\n", n, 0);
	printf("   printf d %d %d\n", n, 0);
	printf("%d\n\n\n", ret);


	ret = ft_printf("ft_printf x %x\n", n);
	printf("   printf x %x\n", n);
	printf("%d\n\n\n", ret);


	ret = ft_printf("ft_printf X %X\n", n);
	printf("   printf X %X\n", n);
	printf("%d\n\n\n", ret);


	ret = ft_printf("ft_printf per %%\n");
	printf("   printf per %%\n");
	printf("%d\n\n\n", ret);

	return 0;
}

*/