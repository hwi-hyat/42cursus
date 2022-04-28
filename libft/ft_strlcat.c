/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:45 by siykim            #+#    #+#             */
/*   Updated: 2022/04/28 11:33:13 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t			i;
	size_t			j;
	unsigned int	out;

	i = ft_strlen(dst);
	out = ft_strlen(dst);
	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	j = 0;
	while (1)
	{
		dst[i] = src[j];
		if (src[j] == '\0')
			break ;
		else if (i == dstsize - 1)
		{
			dst[i] = '\0';
			break ;
		}
		i++;
		j++;
	}
	return (out + ft_strlen(src));
}
