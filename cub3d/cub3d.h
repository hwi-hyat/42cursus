/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:25:13 by siykim            #+#    #+#             */
/*   Updated: 2023/03/07 15:26:44 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<unistd.h>
# include<stdio.h>

typedef struct s_move
{
	int n;
	int e;
	int w;
	int s;
}	t_move;

typedef struct s_gameinfo
{
	t_move m;

}	t_gameinfo;


#endif