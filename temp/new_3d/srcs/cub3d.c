/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:00:04 by cclaude           #+#    #+#             */
/*   Updated: 2023/05/11 11:21:26 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw(t_info *f)
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

int	ft_cubed(t_info *f, char *mapname)
{
	f->mlx.ptr = mlx_init();
	if (ft_parse(f, mapname) == -1)
		return (ft_close(f, 0));
	ft_rotate(f, 1);
	ft_move(f, 1);
	ft_rotate(f, -1);
	ft_move(f, -1);
	f->win.ptr = mlx_new_window(f->mlx.ptr, f->win.x, f->win.y, "cub3D");
	ft_draw(f);
	mlx_hook(f->win.ptr, 2, 0, ft_key, f);
	mlx_hook(f->win.ptr, 17, 0, ft_close, f);
	mlx_loop(f->mlx.ptr);
	return (1);
}

void	ft_init(t_info *f)
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
	f->map.spr = 0;
	f->tex.n = NULL;
	f->tex.s = NULL;
	f->tex.e = NULL;
	f->tex.w = NULL;
	f->tex.i = NULL;
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

	if (argc == 2 && ft_namecheck(argv[1], "cub"))
	{
		ft_init(&f);
	}
	else
		write(2, "Error : Invalid arguments\n", 26);

	ft_cubed(&f, argv[1]);
	return (0);
}
