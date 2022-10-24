/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:33:37 by siykim            #+#    #+#             */
/*   Updated: 2022/10/25 01:01:23 by siykim           ###   ########.fr       */
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
	int	y;
	int	x;
}t_map_info;

//libft
void	*ft_calloc(size_t nmemb, size_t size);

//00_util.c
void	error_exit(int error_code);
void	liberator(char **map, t_map_info *info);
void	malloc_error_esc(char **map, t_map_info *info);

//01_parse_map.c
void	x_check(int *info_x, int x);
void	map_checker(t_map_info *info);
char	*line_parser(int fd, int x);
char	**map_parser(t_map_info *info);
char	**parse_map(t_map_info *info);

#endif