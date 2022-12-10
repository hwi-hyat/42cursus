/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:19:20 by siykim            #+#    #+#             */
/*   Updated: 2022/12/10 16:22:39 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_info *info, t_philo *philo)
{
	philo->time = get_time();
	p_printf(info, philo->p_id, "is eating");
	(philo->eat_cnt)++;
	ft_usleep(info, EATING);
}

static int	philo_routine(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->forks_mutex[philo->left_fork]));
	p_printf(info, philo->p_id, "has taken a fork");
	pthread_mutex_lock(&(info->forks_mutex[philo->right_fork]));
	p_printf(info, philo->p_id, "has taken a fork");
	philo_eat(philo->info, philo);
	pthread_mutex_unlock(&(info->forks_mutex[philo->left_fork]));
	pthread_mutex_unlock(&(info->forks_mutex[philo->right_fork]));
	if (info->eat_check)
		return (1);
	return (0);
}

static void	*ft_philo_func(void *data)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)data;
	info = philo->info;
	if (philo->p_id % 2)
		usleep(10000);
	while (!(info->die_check))
	{
		if (philo_routine(info, philo))
			break ;
		p_printf(info, philo->p_id, "is sleeping");
		ft_usleep(info, SLEEPING);
		p_printf(info, philo->p_id, "is thinking");
	}
	return ((void *)0);
}

void	ft_end_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
		pthread_mutex_destroy(&(info->forks_mutex[i++]));
	pthread_mutex_destroy(&(info->buffer_mutex));
	i = 0;
	while (i < info->num_philo)
		pthread_join(philo[i++].philo_thread, NULL);
	free(info->philos);
	free(info->forks_mutex);
}

int	ft_philo_start(t_info *info, t_philo *philo)
{
	int		i;

	i = 0;
	info->start_time = get_time();
	while (i < info->num_philo)
	{	
		philo[i].time = get_time();
		if (pthread_create(&(philo[i].philo_thread), NULL
				, ft_philo_func, (void *)&philo[i]))
			return (0);
		i++;
	}
	ft_death_check(info, info->philos);
	ft_end_philo(info, info->philos);
	return (1);
}
