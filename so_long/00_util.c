/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:56:16 by siykim            #+#    #+#             */
/*   Updated: 2022/10/21 23:01:28 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	error_exit(int error_code)
{
	if (error_code == 0)
		write(2, "invalid map\n", 12);
	else if (error_code == 1)
		write(2, "allocation error\n", 17);
	
	
	
	exit(1);
}

void	liberator(char **map, t_map_info *info)
{
	int	i;

	i = 0;
	while (i < info->y)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

void	malloc_error_esc(char **map, t_map_info *info)
{
	liberator(map, info);
	error_exit(1);
}