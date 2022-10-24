/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:33:39 by siykim            #+#    #+#             */
/*   Updated: 2022/10/25 01:02:04 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char		**map;
	t_map_info	info;

	map = parse_map(&info);
	printf("info y %d x %d\n", info.y, info.x);

	for(int i = 0; i < info.y; i++)
	{
		for(int j = 0; j < info.x; j++)
			printf("%c", map[i][j]);
		//printf("\n");
	}

	void *mlx_ptr;
	void *win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
	return (0);
}