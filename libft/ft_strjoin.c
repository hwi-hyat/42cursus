/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:43 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:32:44 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlen(const char *s);

size_t	initializer(size_t *s1len, size_t *s2len,
		char const *s1, char const *s2)
{
	*s1len = ft_strlen(s1);
	*s2len = ft_strlen(s2);
	return (*s1len + *s2len + 1);
}

size_t	filler(char *out, char const *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		out[i] = str[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*out;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	out = (char *)malloc(sizeof(char) * initializer(&s1len, &s2len, s1, s2));
	if (out == NULL)
		return (NULL);
	i = 0;
	i += filler(out, s1, s1len);
	i += filler(&out[i], s2, s2len);
	out[i] = 0;
	return (out);
}
