/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:00:04 by cclaude           #+#    #+#             */
/*   Updated: 2023/05/16 00:36:48 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_info *f)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	f->ray = ray;
	f->hit = hit;
	ft_screen(f);
	mlx_put_image_to_window(f->mlx.ptr, f->win.ptr, f->img.ptr, 0, 0);
	free(f->img.ptr);
	free(f->img.adr);
}

int	game(t_info *f, char *mapname)
{
	f->mlx.ptr = mlx_init();
	if (parse(f, mapname) == -1)
		return (ft_close(f, 0));
	ft_rotate(f, 1);
	ft_move(f, 1);
	ft_rotate(f, -1);
	ft_move(f, -1);
	f->win.ptr = mlx_new_window(f->mlx.ptr, f->win.x, f->win.y, "cub3D");
	display(f);
	mlx_hook(f->win.ptr, 2, 0, ft_key, f);
	mlx_hook(f->win.ptr, 17, 0, ft_close, f);
	mlx_loop(f->mlx.ptr);
	return (1);
}

void	initiate(t_info *f)
{
	f->mlx.ptr = NULL;
	f->win.ptr = NULL;
	f->win.x = 0;
	f->win.y = 0;
	f->img.ptr = NULL;
	f->img.adr = NULL;
	f->img.fsh = 0;
	f->err.n = 0;
	f->err.m = 0;
	f->err.p = 0;
	f->map.tab = NULL;
	f->map.x = 0;
	f->map.y = 0;
	f->tex.n = NULL;
	f->tex.s = NULL;
	f->tex.e = NULL;
	f->tex.w = NULL;
	f->tex.c = NONE;
	f->tex.f = NONE;
	f->pos.x = 0;
	f->pos.y = 0;
	f->dir.x = 0;
	f->dir.y = 0;
	f->spr = NULL;
	f->stk = NULL;
}

int	main(int argc, char **argv)
{
	t_info	f;

	if (argc == 2 && check_mapname(argv[1], "cub"))
	{
		initiate(&f);
	}
	else
		write(2, "Error : Invalid arguments\n", 26);
	game(&f, argv[1]);
	return (0);
}
