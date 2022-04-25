/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:30:20 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:30:20 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*out;
	size_t	i;

	out = (void *)malloc(size * nmemb);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		out[i] = 0;
		i++;
	}
	return ((void *)out);
}
