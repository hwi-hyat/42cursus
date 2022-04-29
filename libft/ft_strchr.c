/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:38 by siykim            #+#    #+#             */
/*   Updated: 2022/04/29 23:03:25 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	while (s[i] || c == 0)
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}
