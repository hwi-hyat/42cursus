/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:23 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:32:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cb;

	cb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		cb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
