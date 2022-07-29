/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:02:11 by siykim            #+#    #+#             */
/*   Updated: 2022/07/29 12:54:18 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char g_tmp;

void	sig1(void)
{
	g_tmp >>= 1;
}

void	sig2(void)
{
	g_tmp >>= 1;
	g_tmp += 128;
}

void	running(void)
{
	int	sig_cnt;

	sig_cnt = 0;
	while (1)
	{
		pause();
		if (sig_cnt == 7)
		{
			if (g_tmp != 0)
				write(1, &g_tmp, 1);
			else
				write(1, "\n", 1);
			sig_cnt = 0;
		}
		else
			sig_cnt++;
	}
}

int	main(void)
{
	signal(SIGUSR1, sig1);
	signal(SIGUSR2, sig2);
	ft_printf("Process ID : %d\n", getpid());
	running();
	return (0);
}