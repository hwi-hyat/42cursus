/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:37:37 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 00:55:56 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	obj_check(t_map_info *info, t_map_check *check, char buf)
{
	if (buf == 'C')
		info->c_cnt++;
	else if (buf == 'P')
	{
		info->p_cnt++;
		info->p_y = check->y_count;
		info->p_x = check->x_count;
	}
	else if (buf == 'E')
		info->e_cnt++;
	else if (buf != '1' && buf != '0' && buf != 'P'
		&& buf != 'C' && buf != 'E' && buf != '\n')
		code_exit(1);
}

void	map_checker(t_map_info *info, t_map_check *check)
{
	int			map_fd;
	char		buf;

	map_fd = open("map.ber", O_RDONLY);
	while (read(map_fd, &buf, 1) > 0)
	{
		obj_check(info, check, buf);
		check->x_count++;
		if (buf == '\n')
		{
			if (info->x == 0)
				info->x = check->x_count;
			else if (info->x != check->x_count)
				code_exit(1);
			check->x_count = 0;
			check->y_count++;
		}
	}
	info->y = check->y_count;
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

void	map_parser(t_map_info *info)
{
	int		map_fd;
	int		i;

	info->map = (char **)ft_calloc(info->y, sizeof(char *));
	if (!info->map)
		code_exit(2);
	map_fd = open("map.ber", O_RDONLY);
	i = 0;
	while (i < info->y)
	{
		info->map[i] = line_parser(map_fd, info->x);
		if (!info->map[i])
			liberate_esc(info, 2);
		i++;
	}
}

void	parse_map(t_map_info *info)
{
	t_map_check	check;

	check.y_count = 0;
	check.x_count = 0;
	info->c_cnt = 0;
	info->p_cnt = 0;
	info->e_cnt = 0;
	info->x = 0;
	info->y = 0;
	info->moves = 0;
	map_checker(info, &check);
	map_parser(info);
	wall_check(info, &check);
}
