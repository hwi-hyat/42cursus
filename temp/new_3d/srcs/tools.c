/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:01:54 by cclaude           #+#    #+#             */
/*   Updated: 2023/05/11 11:55:53 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
		|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int	ft_atoi(char *line, int *i)
{
	int	num;

	num = 0;
	ft_spaceskip(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

int	print_error2(int code)
{
	if (code == -10)
		write(2, "error : Invalid line in file\n", 29);
	else if (code == -11)
		write(2, "error : Malloc fail (map table)\n", 32);
	else if (code == -12)
		write(2, "error : Invalid map\n", 20);
	else if (code == -13)
		write(2, "error : Map isn't a rectangle\n", 30);
	else if (code == -14)
		write(2, "error : No resolution specified\n", 32);
	else if (code == -15)
		write(2, "error : Missing texture\n", 24);
	else if (code == -16)
		write(2, "error : Missing floor/ceiling color\n", 26);
	else if (code == -17)
		write(2, "error : No starting position\n", 29);
	else if (code == -18)
		write(2, "error : Multiple starting positions\n", 36);
	else if (code == -19)
		write(2, "error : Map isn't surrounded by walls\n", 38);
}

int	print_error(int code)
{
	if (code <= -10)
		print_error2(code);
	else if (code == -1)
		write(2, "error : Couldn't open file (FD)\n", 32);
	else if (code == -2)
		write(2, "error : Couldn't parse file (GNL)\n", 34);
	else if (code == -3)
		write(2, "error : Resolution specified twice\n", 35);
	else if (code == -4)
		write(2, "error : Invalid resolution\n", 27);
	else if (code == -5)
		write(2, "error : Floor/ceiling specified twice\n", 38);
	else if (code == -6)
		write(2, "error : Invalid floor/ceiling line\n", 35);
	else if (code == -7)
		write(2, "error : Texture path specified twice\n", 37);
	else if (code == -8)
		write(2, "error : Malloc fail (texture path)\n", 35);
	else if (code == -9)
		write(2, "error : Invalid texture image\n", 30);
	return (-1);
}
