/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:19:59 by siykim            #+#    #+#             */
/*   Updated: 2022/12/10 16:25:44 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (check_arguments(argc, argv) == 0
		|| init_info(argc, argv, &info) == 0)
		return (ft_print_error("Check Arguments"));
	if (info.num_philo == 1)
		return (ft_print_error("Number of Philosopher cannot be 1\n"));
	if (ft_philo_start(&info, (&info)->philos) == 0)
		return (ft_print_error("Thread Create Fail\n"));
	return (0);
}
