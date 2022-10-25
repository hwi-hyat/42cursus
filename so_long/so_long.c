/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:33:39 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 01:04:20 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_map_info *info)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "mlx 42");
	mlx_hook(window, 2, 0, &key_input, info);
	mlx_loop(mlx);
}

int	main(void)
{
	t_map_info	info;

	parse_map(&info);
	printf("info y %d x %d p_y %d p_x %d\n", info.y, info.x, info.p_y, info.p_x);

	for(int i = 0; i < info.y; i++)
		for(int j = 0; j < info.x; j++)
			printf("%c", info.map[i][j]);

	init_game(&info);
	
	return (0);
}