/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_set_image copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:02:47 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 17:13:24 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	load_image(t_map_info *f)
{
	int	w;
	int	h;

	f->p[0] = mlx_xpm_file_to_image(f->mlx, "./img/p0.xpm", &w, &h);
	f->p[1] = mlx_xpm_file_to_image(f->mlx, "./img/p1.xpm", &w, &h);
	f->p[2] = mlx_xpm_file_to_image(f->mlx, "./img/p2.xpm", &w, &h);
	f->p[3] = mlx_xpm_file_to_image(f->mlx, "./img/p3.xpm", &w, &h);
	f->wall = mlx_xpm_file_to_image(f->mlx, "./img/wall.xpm", &w, &h);
	f->ground = mlx_xpm_file_to_image(f->mlx, "./img/floor.xpm", &w, &h);
	f->exit[0] = mlx_xpm_file_to_image(f->mlx, "./img/doorc.xpm", &w, &h);
	f->exit[1] = mlx_xpm_file_to_image(f->mlx, "./img/dooro.xpm", &w, &h);
	f->collect = mlx_xpm_file_to_image(f->mlx, "./img/colle.xpm", &w, &h);
}

void	print_obj(t_map_info *f, char c, int i, int j)
{
	int	act;
	int	i32;
	int	j32;

	i32 = i * 32;
	j32 = j * 32;
	act = f->moves % 4;
	mlx_put_image_to_window(f->mlx, f->win, f->ground, j32, i32);
	if (c == '1')
		mlx_put_image_to_window(f->mlx, f->win, f->wall, j32, i32);
	if (c == 'P')
		mlx_put_image_to_window(f->mlx, f->win, f->p[act], j32 + 4, i32 + 4);
	else if (c == 'C')
		mlx_put_image_to_window(f->mlx, f->win, f->collect, j32 + 8, i32 + 8);
	else if (c == 'E' && f->c_cnt)
		mlx_put_image_to_window(f->mlx, f->win, f->exit[0], j32, i32);
	else if (c == 'E' && !f->c_cnt)
		mlx_put_image_to_window(f->mlx, f->win, f->exit[1], j32, i32);
}

void	paint_map(t_map_info *f)
{
	int		i;
	int		j;
	char	*move_c;

	i = 0;
	while (i < f->y)
	{
		j = 0;
		while (j < f->x - 1)
		{
			print_obj(f, f->map[i][j], i, j);
			j++;
		}
		i++;
	}
	move_c = ft_itoa(f->moves);
	if (move_c == NULL)
		liberate_esc(f, 2);
	mlx_string_put(f->mlx, f->win, 12, 20, 0x00FFFFFF, move_c);
	free(move_c);
}

void	set_image(t_map_info *f)
{
	load_image(f);
	paint_map(f);
}
