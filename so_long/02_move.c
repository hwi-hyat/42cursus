/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:58:33 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 16:43:33 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	move_up(t_map_info *f)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = f->p_y - 1;
	np_x = f->p_x;
	next = f->map[np_y][np_x];
	if ((np_y <= 0 || f->y - 1 <= np_y || np_x <= 0
			|| f->x - 2 <= np_x || next == '1')
		|| (next == 'E' && f->c_cnt != 0))
		return (0);
	f->map[np_y][np_x] = f->map[f->p_y][f->p_x];
	f->map[f->p_y][f->p_x] = '0';
	f->p_y = np_y;
	f->p_x = np_x;
	f->moves++;
	return (next);
}

char	move_left(t_map_info *f)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = f->p_y;
	np_x = f->p_x - 1;
	next = f->map[np_y][np_x];
	if ((np_y <= 0 || f->y - 1 <= np_y || np_x <= 0
			|| f->x - 2 <= np_x || next == '1')
		|| (next == 'E' && f->c_cnt != 0))
		return (0);
	f->map[np_y][np_x] = f->map[f->p_y][f->p_x];
	f->map[f->p_y][f->p_x] = '0';
	f->p_y = np_y;
	f->p_x = np_x;
	f->moves++;
	return (next);
}

char	move_down(t_map_info *f)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = f->p_y + 1;
	np_x = f->p_x;
	next = f->map[np_y][np_x];
	if ((np_y <= 0 || f->y - 1 <= np_y || np_x <= 0
			|| f->x - 2 <= np_x || next == '1')
		|| (next == 'E' && f->c_cnt != 0))
		return (0);
	f->map[np_y][np_x] = f->map[f->p_y][f->p_x];
	f->map[f->p_y][f->p_x] = '0';
	f->p_y = np_y;
	f->p_x = np_x;
	f->moves++;
	return (next);
}

char	move_right(t_map_info *f)
{
	int		np_y;
	int		np_x;
	char	next;

	np_y = f->p_y;
	np_x = f->p_x + 1;
	next = f->map[np_y][np_x];
	if ((np_y <= 0 || f->y - 1 <= np_y || np_x <= 0
			|| f->x - 2 <= np_x || next == '1')
		|| (next == 'E' && f->c_cnt != 0))
		return (0);
	f->map[np_y][np_x] = f->map[f->p_y][f->p_x];
	f->map[f->p_y][f->p_x] = '0';
	f->p_y = np_y;
	f->p_x = np_x;
	f->moves++;
	return (next);
}

void	move(t_map_info *f, int dir)
{
	char	next;

	next = 0;
	if (dir == 13)
		next = move_up(f);
	else if (dir == 0)
		next = move_left(f);
	else if (dir == 1)
		next = move_down(f);
	else if (dir == 2)
		next = move_right(f);
	if (next == 'C')
		f->c_cnt--;
	else if (next == 'E')
		liberate_esc(f, 0);
}
