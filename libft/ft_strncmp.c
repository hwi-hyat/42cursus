/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:53 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:32:53 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{	
		if (us1[i] - us2[i] != 0)
			return (us1[i] - us2[i]);
		if (us1[i] == '\0' || us2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
