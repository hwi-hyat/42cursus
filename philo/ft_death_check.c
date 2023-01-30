/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:17:51 by siykim            #+#    #+#             */
/*   Updated: 2022/12/12 20:10:31 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_check(t_info *info, t_philo *philo)
{
	int	philo_id;

	philo_id = 0;
	while (info->num_must_eat > 0 && philo_id < info->num_philo
		&& philo[philo_id].eat_cnt >= info->num_must_eat)
		philo_id++;
	if (philo_id == info->num_philo)
		info->eat_check = 1;
}

void	ft_death_check(t_info *info, t_philo *philo)
{
	int	i;

	while (!(info->eat_check))
	{
		i = 0;
		while ((i < info->num_philo) && (!(info->die_check)))
		{
			if ((get_time() - philo[i].time) > info->t2d)
			{
				p_printf(info, i, "died");
				info->die_check = 1;
			}
			usleep(100);
			i++;
		}
		if (info->die_check)
			break ;
		ft_eat_check(info, info->philos);
	}
}
