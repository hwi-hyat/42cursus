/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:06:53 by siykim            #+#    #+#             */
/*   Updated: 2022/10/25 00:12:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*out;
	size_t	i;

	out = (void *)malloc(size * count);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		out[i] = 0;
		i++;
	}
	return ((void *)out);
}