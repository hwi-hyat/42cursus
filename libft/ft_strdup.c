/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:40 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:32:40 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	while (s[i] != 0)
		i++;
	out = (char *)malloc(sizeof(char) * i + 1);
	if (out == 0)
		return (0);
	j = 0;
	while (j != i)
	{
		out[j] = s[j];
		j++;
	}
	out[j] = '\0';
	return (out);
}
