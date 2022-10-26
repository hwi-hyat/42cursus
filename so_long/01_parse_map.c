/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:37:37 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 17:36:17 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	obj_check(t_map_info *f, t_map_check *check, char buf)
{
	if (buf == 'C')
		f->c_cnt++;
	else if (buf == 'P')
	{
		f->p_cnt++;
		f->p_y = check->y_count;
		f->p_x = check->x_count;
	}
	else if (buf == 'E')
		f->e_cnt++;
	else if (buf != '1' && buf != '0' && buf != 'P'
		&& buf != 'C' && buf != 'E' && buf != '\n')
		code_exit(1);
}

void	map_checker(t_map_info *f, t_map_check *check)
{
	int			map_fd;
	char		buf;

	map_fd = open("map.ber", O_RDONLY);
	while (read(map_fd, &buf, 1) > 0)
	{
		obj_check(f, check, buf);
		check->x_count++;
		if (buf == '\n')
		{
			if (f->x == 0)
				f->x = check->x_count;
			else if (f->x != check->x_count)
				code_exit(1);
			check->x_count = 0;
			check->y_count++;
		}
	}
	f->y = check->y_count;
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

void	map_parser(t_map_info *f)
{
	int		map_fd;
	int		i;

	f->map = (char **)ft_calloc(f->y, sizeof(char *));
	if (!f->map)
		code_exit(2);
	map_fd = open("map.ber", O_RDONLY);
	i = 0;
	while (i < f->y)
	{
		f->map[i] = line_parser(map_fd, f->x);
		if (!f->map[i])
			liberate_esc(f, 2);
		i++;
	}
}

void	parse_map(t_map_info *f)
{
	t_map_check	check;

	check.y_count = 0;
	check.x_count = 0;
	f->c_cnt = 0;
	f->p_cnt = 0;
	f->e_cnt = 0;
	f->x = 0;
	f->y = 0;
	f->moves = 0;
	map_checker(f, &check);
	map_parser(f);
	wall_check(f);
}
