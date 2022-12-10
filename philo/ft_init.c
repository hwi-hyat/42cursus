/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:18:50 by siykim            #+#    #+#             */
/*   Updated: 2022/12/10 15:18:51 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_info *info)
{
	int	i;

	info->philos = (t_philo *)malloc(info->num_philo * sizeof(t_philo));
	if (info->philos == NULL)
		return (0);
	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].p_id = i;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->num_philo;
		info->philos[i].eat_cnt = 0;
		info->philos[i].time = 0;
		info->philos[i].info = info;
		i++;
	}
	return (1);
}

static int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->buffer_mutex), NULL))
		return (0);
	info->forks_mutex = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (info->forks_mutex == NULL)
		return (0);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_mutex_init(&(info->forks_mutex[i]), NULL))
			return (0);
		i++;
	}
	return (1);
}

int	init_info(int argc, char **argv, t_info *info)
{
	info->num_philo = (int)ft_atoull(argv[1]);
	info->t2d = ft_atoull(argv[2]);
	info->t2e = ft_atoull(argv[3]);
	info->t2s = ft_atoull(argv[4]);
	info->num_must_eat = -1;
	info->die_check = 0;
	info->eat_check = 0;
	info->start_time = 0;
	if (argc == 6)
	{
		info->num_must_eat = (int)ft_atoull(argv[5]);
		if (info->num_must_eat <= 0)
			return (0);
	}
	if (init_mutex(info) == 0)
		return (0);
	if (init_philo(info) == 0)
		return (0);
	return (1);
}
