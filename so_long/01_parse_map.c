/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:37:37 by siykim            #+#    #+#             */
/*   Updated: 2022/10/25 00:53:35 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	x_check(int *info_x, int x)
{
	if (*info_x == 0)
		*info_x = x;
	else if (*info_x != x)
		error_exit(0);
}

void	map_checker(t_map_info *info)
{
	char	buf;
	int		map_fd;
	int		y_count;
	int		x_count;

	map_fd = open("map.ber", O_RDONLY);
	y_count = 0;
	x_count = 0;
	while (read(map_fd, &buf, 1) > 0)
	{
		x_count++;
		if (buf == '\n')
		{
			x_check(&info->x, x_count);
			x_count = 0;
			y_count++;
		}
	}
	info->y = y_count;
	close(map_fd);
}

char	*line_parser(int fd, int x)
{
	int		i;
	char	*out;
	char	buf;

	out = (char *)ft_calloc(x, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < x)
	{
		read(fd, &buf, 1);
		out[i] = buf;
		i++;
	}
	return (out);
}

char	**map_parser(t_map_info *info)
{
	char	**map;
	int		map_fd;
	int		i;

	map = (char **)ft_calloc(info->y, sizeof(char *));
	if (!map)
		error_exit(1);
	map_fd = open("map.ber", O_RDONLY);
	i = 0;
	while (i < info->y)
	{
		map[i] = line_parser(map_fd, info->x);
		if (!map[i])
			malloc_error_esc(map, info);
		i++;
	}
	return (map);
}

char	**parse_map(t_map_info *info)
{
	char		**map;

	info->x = 0;
	info->y = 0;
	map_checker(info);
	map = map_parser(info);
	return (map);
}
