/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:57 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:32:57 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if (c == 0)
		return (&((char *)s)[size]);
	while (size)
	{
		size--;
		if (s[size] == c)
			return (&((char *)s)[size]);
	}
	return (0);
}
