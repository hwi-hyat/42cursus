/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:50:40 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 17:35:46 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	wall_check(t_map_info *f)
{
	int	i;

	i = 0;
	while (i < f->y)
	{
		if (f->map[i][0] != '1' || f->map[i][f->x - 2] != '1')
			liberate_esc(f, 1);
		i++;
	}
	i = 0;
	while (i < f->x - 1)
	{
		if (f->map[0][i] != '1' || f->map[f->y - 1][i] != '1')
			liberate_esc(f, 1);
		i++;
	}
	if (f->c_cnt <= 0 || f->e_cnt <= 0 || f->p_cnt != 1)
		liberate_esc(f, 1);
}