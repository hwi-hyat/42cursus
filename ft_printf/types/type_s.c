/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:13:58 by siykim            #+#    #+#             */
/*   Updated: 2022/05/03 01:24:33 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

int ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len++])
	return (len);
}

int	type_s(va_list ap)
{
	char *out;
	int	len;

	out = va_args(ap, )
	len = ft_strlen(ap);
	write(1, ap, len);
	return (len);
}
