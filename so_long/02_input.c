/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:19:59 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 17:15:59 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	key_input(int input, t_map_info *f)
{
	if (input == 53)
		liberate_esc(f, 0);
	else
		move(f, input);
	printf("move count %d\n", f->moves);
	paint_map(f);
	return (0);
}
