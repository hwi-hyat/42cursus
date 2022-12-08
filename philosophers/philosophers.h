/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:49:54 by siykim            #+#    #+#             */
/*   Updated: 2022/11/21 23:04:43 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<pthread.h>
# include<sys/time.h>

typedef struct s_args
{
	int	nop;
	int	t2d;
	int	t2e;
	int	t2s;
	int	must_eat;
}	t_args;

typedef struct s_info
{
	t_args			args;
	pthread_t		*philo;
	pthread_mutex_t	*forks;
}	t_info



//util.c
int	a_to_i(const char *str);

//routine.c
void	routine(t_info *info);

#endif