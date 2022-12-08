/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:49:04 by siykim            #+#    #+#             */
/*   Updated: 2022/11/21 22:50:14 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	get_args(int argc, char **argv, t_args *args)
{
	args->nop = 0;
	args->t2d = 0;
	args->t2e = 0;
	args->t2s = 0;
	args->must_eat = 0;
	if(argc == 5)
	{
		args->nop = a_to_i(argv[1]);
		args->t2d = a_to_i(argv[2]);
		args->t2e = a_to_i(argv[3]);
		args->t2s = a_to_i(argv[4]);
	}
	else if(argc == 6)
		args->must_eat = a_to_i(argv[5]);
	if(args->nop == 0 || args->t2d == 0 || args->t2e== 0 
		|| args->t2s == 0 || (argc == 6 && args->must_eat == 0))
		return (-1);
	return (0);
}

void	set_info(t_info *info)
{
	info->philo = (pthread_t *)malloc(sizeof(pthread_t) * info->args.nop);
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->args.nop);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if(get_args(argc, argv, &info.args) == -1)
	{
		write(2, "input error\n", 12);
		return (-1);
	}
	set_info(&info);
	init_thread(&info);
	return (0);
}