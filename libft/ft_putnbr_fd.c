/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:32:30 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:35:56 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	reverser(char rev[11], int edge, int fd)
{
	char	out[11];
	int		i;

	i = 0;
	while (edge >= 0)
	{
		out[i] = rev[edge];
		i++;
		edge--;
	}
	write(fd, out, i);
}

void	printer(int n, int fd)
{
	char	rev[11];
	int		edge;

	edge = 0;
	while (n != 0)
	{
		rev[edge] = n % 10 + 48;
		n /= 10;
		if (n == 0)
			break ;
		edge++;
	}
	reverser(rev, edge, fd);
}

void	printer_neg(int n, int fd)
{
	char	rev[11];
	int		edge;

	edge = 0;
	while (n != 0)
	{
		rev[edge] = -(n % 10) + 48;
		n /= 10;
		if (n == 0)
			break ;
		edge++;
	}
	edge++;
	rev[edge] = '-';
	reverser(rev, edge, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
		printer_neg(n, fd);
	else
		printer(n, fd);
}
