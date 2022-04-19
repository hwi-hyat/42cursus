/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:28 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:32:29 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	length;

	if (s == NULL)
		return ;
	length = 0;
	while (1)
	{
		if (s[length] == '\0')
			break ;
		length++;
	}
	write(fd, s, length);
	write(fd, "\n", 1);
}
