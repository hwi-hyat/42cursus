/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:58:33 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 01:20:14 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	move_up(t_map_info *info)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = info->p_y - 1;
	np_x = info->p_x;
	next = info->map[np_y][np_x];
	if ((np_y <= 0 || info->y - 1 <= np_y || np_x <= 0
			|| info->x - 2 <= np_x || next == '1')
		|| (next == 'E' && info->c_cnt != 0))
		return (0);
	info->map[np_y][np_x] = info->map[info->p_y][info->p_x];
	info->map[info->p_y][info->p_x] = '0';
	info->p_y = np_y;
	info->p_x = np_x;
	return (next);
}

char	move_left(t_map_info *info)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = info->p_y;
	np_x = info->p_x - 1;
	next = info->map[np_y][np_x];
	if ((np_y <= 0 || info->y - 1 <= np_y || np_x <= 0
			|| info->x - 2 <= np_x || next == '1')
		|| (next == 'E' && info->c_cnt != 0))
		return (0);
	info->map[np_y][np_x] = info->map[info->p_y][info->p_x];
	info->map[info->p_y][info->p_x] = '0';
	info->p_y = np_y;
	info->p_x = np_x;
	return (next);
}

char	move_down(t_map_info *info)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = info->p_y + 1;
	np_x = info->p_x;
	next = info->map[np_y][np_x];
	if ((np_y <= 0 || info->y - 1 <= np_y || np_x <= 0
			|| info->x - 2 <= np_x || next == '1')
		|| (next == 'E' && info->c_cnt != 0))
		return (0);
	info->map[np_y][np_x] = info->map[info->p_y][info->p_x];
	info->map[info->p_y][info->p_x] = '0';
	info->p_y = np_y;
	info->p_x = np_x;
	return (next);
}

char	move_right(t_map_info *info)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = info->p_y;
	np_x = info->p_x + 1;
	next = info->map[np_y][np_x];
	if ((np_y <= 0 || info->y - 1 <= np_y || np_x <= 0
			|| info->x - 2 <= np_x || next == '1')
		|| (next == 'E' && info->c_cnt != 0))
		return (0);
	info->map[np_y][np_x] = info->map[info->p_y][info->p_x];
	info->map[info->p_y][info->p_x] = '0';
	info->p_y = np_y;
	info->p_x = np_x;
	return (next);
}

void	move(t_map_info *info, int dir)
{
	char	next;

	next = 0;
	if (dir == 13)
		next = move_up(info);
	else if (dir == 0)
		next = move_left(info);
	else if (dir == 1)
		next = move_down(info);
	else if (dir == 2)
		next = move_right(info);
	if (next == 'C')
		info->c_cnt--;
	else if (next == 'E')
		liberate_esc(info, 0);
}
