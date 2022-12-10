/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:18:57 by siykim            #+#    #+#             */
/*   Updated: 2022/12/10 16:25:57 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EATING		1
# define SLEEPING	2

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

struct						s_info;

typedef unsigned long long	t_ull;

typedef struct s_philo {
	int					p_id;
	int					left_fork;
	int					right_fork;
	int					eat_cnt;
	pthread_t			philo_thread;
	struct s_info		*info;
	unsigned long long	time;
}	t_philo;

typedef struct s_info {
	int					num_philo;
	int					num_must_eat;
	int					eat_check;
	int					die_check;
	unsigned long long	t2d;
	unsigned long long	t2e;
	unsigned long long	t2s;
	unsigned long long	start_time;
	pthread_mutex_t		buffer_mutex;
	pthread_mutex_t		*forks_mutex;
	t_philo				*philos;
}	t_info;

int					check_arguments(int argc, char **argv);
int					init_info(int argc, char **argv, t_info *info);
int					ft_philo_start(t_info *info, t_philo *philo);
int					ft_print_error(char *str);
void				p_printf(t_info *info, int p_id, char *str);
void				ft_death_check(t_info *info, t_philo *philo);
void				ft_usleep(t_info *info, int type);
unsigned long long	ft_atoull(char *str);
unsigned long long	get_time(void);

#endif
