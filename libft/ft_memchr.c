/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:31:50 by siykim            #+#    #+#             */
/*   Updated: 2022/04/24 16:22:25 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*cs;

	if (n == 0)
		return (NULL);
	i = 0;
	cs = (char *)s;
	while (cs[i] && i < n)
	{
		if (cs[i] == (char)c)
			return (&cs[i]);
		i++;
	}
	if (c == 0)
		return (&cs[i]);
	return (0);
}
