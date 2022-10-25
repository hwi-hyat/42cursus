/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:50:40 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 00:57:33 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	wall_check(t_map_info *info, t_map_check *check)
{
	int	i;

	i = 0;
	while (i < info->y)
	{
		if (info->map[i][0] != '1' || info->map[i][info->x - 2] != '1')
			liberate_esc(info, 1);
		i++;
	}
	i = 0;
	while (i < check->x_count)
	{
		if (info->map[0][i] != '1' || info->map[info->y - 1][i] != '1')
			liberate_esc(info, 1);
		i++;
	}
	if (info->c_cnt <= 0 || info->e_cnt <= 0 || info->p_cnt != 1)
		liberate_esc(info, 1);
}