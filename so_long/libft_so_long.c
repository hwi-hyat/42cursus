/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:06:53 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 17:06:06 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*out;
	size_t	i;

	out = (void *)malloc(size * count);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		out[i] = 0;
		i++;
	}
	return ((void *)out);
}

int	counter(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	neg(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

void	num_disp(char *out, int n, int len)
{
	out[len] = 0;
	len--;
	if (n < 0)
		out[0] = '-';
	while (n != 0)
	{
		out[len] = (n % 10) * neg(n) + '0';
		len--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*out;

	if (n == 0)
	{
		out = (char *)malloc(sizeof(char) * 2);
		if (out == NULL)
			return (NULL);
		out[0] = '0';
		out[1] = '\0';
		return (out);
	}
	out = (char *)malloc(sizeof(char) * (counter(n)) + 1);
	if (out == NULL)
		return (NULL);
	num_disp(out, n, counter(n));
	return (out);
}
