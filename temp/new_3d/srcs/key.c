/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:31:08 by cclaude           #+#    #+#             */
/*   Updated: 2023/05/15 23:17:30 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_info *s, int win)
{
	int	i;

	i = 0;
	while (i < s->map.y)
		free(s->map.tab[i++]);
	free(s->map.tab);
	free(s->tex.n);
	free(s->tex.s);
	free(s->tex.e);
	free(s->tex.w);
	if (win == 1)
		mlx_destroy_window(s->mlx.ptr, s->win.ptr);
	free(s->mlx.ptr);
	exit(0);
	return (1);
}

void	ft_move(t_info *s, double c)
{
	s->pos.x += c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.x -= c * (s->dir.x * SPEED / 100);
	s->pos.y += c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.y -= c * (s->dir.y * SPEED / 100);
}

void	ft_strafe(t_info *s, double c)
{
	s->pos.x -= c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.x += c * (s->dir.y * SPEED / 100);
	s->pos.y += c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.y -= c * (s->dir.x * SPEED / 100);
}

void	ft_rotate(t_info *s, double c)
{
	double	dist;

	s->dir.x = s->dir.x * cos(c * TURN) - s->dir.y * sin(c * TURN);
	s->dir.y = s->dir.y * cos(c * TURN) + s->dir.x * sin(c * TURN);
	dist = hypot(s->dir.x, s->dir.y);
	s->dir.x /= dist;
	s->dir.y /= dist;
}

int	ft_key(int key, void *arg)
{
	if (key == ESC)
		ft_close(arg, 1);
	else if (key == W)
		ft_move(arg, 1);
	else if (key == A)
		ft_strafe(arg, -1);
	else if (key == S)
		ft_move(arg, -1);
	else if (key == D)
		ft_strafe(arg, 1);
	else if (key == LEFT)
		ft_rotate(arg, -1);
	else if (key == RIGHT)
		ft_rotate(arg, 1);
	display(arg);
	printf("dir x : %f, dir y : %f, dir a: %f\n", ((t_info *)arg)->dir.x, ((t_info *)arg)->dir.y, ((t_info *)arg)->dir.a);
	return (1);
}
