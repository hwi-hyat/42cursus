/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:16:30 by siykim            #+#    #+#             */
/*   Updated: 2022/07/14 18:18:27 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	check_fd(t_files *files, t_strings *strs, int fd)
{
	while (files)
	{
		if (files->fd == fd && (*files->line != NULL))
		{
			strs->line = str_dup(files->line, -1);
			free(files->line);
			return ;
		}
		if(files->next == NULL)
		{
			files->next = (t_files *)malloc(sizeof(t_files));
			files->next->fd = fd;
			files->next->prev = files;
			return ;
		}
		files = files->next;
	}
	files = (t_files *)malloc(sizeof(t_files));
	files->fd = fd;
}

int	check_nl(char *line, t_strings *strs, t_files *files)
{
	int	i;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{	
			strs->ret = str_dup(line, i + 1);
			files->line = str_dup(&line[i + 1], -1);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_files	*files;
	t_strings		strs;
	int				read_i;
	
	if (fd < 3)
		return ;
	strs.buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	strs.line = NULL;
	check_fd(files, &strs, fd);
	while(1)
	{
		if (check_nl(strs.line, &strs, files) == 1)
		{
			free(strs.line);
			free(strs.buf);
			return(strs.ret);
		}
		read_i = read(fd, strs.buf, BUFFER_SIZE);
		strs.buf[read_i] = 0;
		if (read_i < 0)
			return (NULL);
		else if (read_i == 0)
		{
			strs.line = nl_attatcher(strs.line);
			continue ;
		}
		
	}
}