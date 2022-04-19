/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:51 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:35:41 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (out == 0)
		return (0);
	while (i < len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
