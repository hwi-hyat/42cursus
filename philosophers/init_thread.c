/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:49:11 by siykim            #+#    #+#             */
/*   Updated: 2022/11/23 11:57:31 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	init_thread(t_info *info)
{
	int			i;

	i = 0;
	while(i < info->args.nop)
	{
		pthread_create(info->philo[i], NULL, routine, info);
		i++;
	}
	


}