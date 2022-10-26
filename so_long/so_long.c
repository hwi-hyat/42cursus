/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:33:39 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 17:07:19 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_map_info *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window
		(f->mlx, (f->x - 1) * 32, f->y * 32, "SO LONG");
	set_image(f);
	mlx_hook(f->win, 2, 0, &key_input, f);
	mlx_loop(f->mlx);
}

int	main(void)
{
	t_map_info	f;

	parse_map(&f);
	init_game(&f);
	return (0);
}
