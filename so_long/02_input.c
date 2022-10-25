/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:19:59 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 01:05:06 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	print_moves(t_map_info *info)
{
	char	*move_c;

	move_c = ft_itoa(info->moves);
	if (move_c == NULL)
		liberate_esc(info, 2);
	write(1, move_c, ft_strlen(move_c));
	write(1, "\n", 1);
	free(move_c);
}

int	key_input(int input, t_map_info *info)
{
	if (input == 53)
		liberate_esc(info, 0);
	else
		move(info, input);
	info->moves++;
	print_moves(info);
	for(int i = 0; i < info->y; i++)
		for(int j = 0; j < info->x; j++)
			printf("%c", info->map[i][j]);
	return (0);
}
