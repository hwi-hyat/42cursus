/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:31:59 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:32:21 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*cdst;
	unsigned char		*csrc;

	if (dst == src)
		return (dst);
	if (dst == 0 && src == 0)
		return (0);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	else
		while (len--)
			cdst[len] = csrc[len];
	return (dst);
}
