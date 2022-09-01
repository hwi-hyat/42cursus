/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:02:16 by siykim            #+#    #+#             */
/*   Updated: 2022/09/01 11:27:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	out;

	i = 0;
	neg = 1;
	out = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		out *= 10;
		out += str[i] - '0';
		i++;
	}
	return (neg * out);
}

void	send(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		i++;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if(argc != 3)
	{
		write(2, "Input Error\n", 12);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (1)
	{
		send(argv[2][i], pid);
		if (argv[2][i] == 0)
			break ;
		i++;
	}
	return (0);
}
