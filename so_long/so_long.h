/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:33:37 by siykim            #+#    #+#             */
/*   Updated: 2022/10/26 01:03:49 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include"./mlx/mlx.h"
# include<stdio.h> // 나중에 지워주기

typedef struct s_map_info {
	char	**map;
	int		y;
	int		x;
	int		p_y;
	int		p_x;
	int		moves;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
}t_map_info;

typedef struct s_map_check {
	int	y_count;
	int	x_count;
}t_map_check;

//libft
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

//00_util.c
void	code_exit(int error_code);
void	liberator(t_map_info *info);
void	normal_esc(t_map_info *info);
void	liberate_esc(t_map_info *info, int code);

//01_parse_map.c
void	obj_check(t_map_info *info, t_map_check *check, char buf);
void	map_checker(t_map_info *info, t_map_check *check);
char	*line_parser(int fd, int x);
void	map_parser(t_map_info *info);
void	parse_map(t_map_info *info);

//01_parse_map_2.c
void	wall_check(t_map_info *info, t_map_check *check);

//02_input.c
int		key_input(int input, t_map_info *info);

//02_move.c
char	move_up(t_map_info *info);
char	move_left(t_map_info *info);
char	move_down(t_map_info *info);
char	move_right(t_map_info *info);
void	move(t_map_info *info, int dir);


#endif