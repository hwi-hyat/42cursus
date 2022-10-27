/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:56:16 by siykim            #+#    #+#             */
/*   Updated: 2022/10/27 15:09:40 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	code_exit(int code)
{
	if (code == 0)
		exit(0);
	else if (code == 1)
		write(2, "invalid map\n", 12);
	else if (code == 2)
		write(2, "allocation error\n", 17);
	exit(1);
}

void	liberator(t_map_info *f)
{
	int	i;

	i = 0;
	while (i < f->y)
	{
		if (f->map[i])
			free(f->map[i]);
		i++;
	}
	if (f->map)
		free(f->map);
}

void	liberate_esc(t_map_info *f, int code)
{
	liberator(f);
	code_exit(code);
}
