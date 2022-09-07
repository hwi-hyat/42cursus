/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:26:10 by siykim            #+#    #+#             */
/*   Updated: 2022/09/07 10:54:05 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_to_i(const char *str, t_stack *stack)
{
	int	i;
	int	neg;
	int	out;

	i = 0;
	neg = 1;
	out = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		out *= 10;
		out += str[i++] - '0';
	}
	if (str[i])
		error(stack);
	return (neg * out);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{	
		if (us1[i] - us2[i] != 0)
			return (us1[i] - us2[i]);
		if (us1[i] == '\0' || us2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

void	error(t_stack *stack)
{
	liberate_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

