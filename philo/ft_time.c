/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:19:38 by siykim            #+#    #+#             */
/*   Updated: 2022/12/10 16:23:07 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((unsigned long long)(t.tv_sec * 1000 + t.tv_usec / 1000));
}

void	ft_usleep(t_info *info, int type)
{
	unsigned long long	target_time;
	unsigned long long	tmp_time;
	unsigned long long	current_time;

	if (type == EATING)
		target_time = (unsigned long long)(info->t2e);
	else if (type == SLEEPING)
		target_time = (unsigned long long)(info->t2s);
	tmp_time = get_time();
	while (!(info->die_check))
	{
		current_time = get_time();
		if ((current_time - tmp_time) >= target_time)
			break ;
		usleep(100);
	}
}
