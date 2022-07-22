/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:16:30 by siykim            #+#    #+#             */
/*   Updated: 2022/07/22 17:46:21 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_fd(t_files **files, t_strings *strs, int fd)
{
	t_files	*files_i;

	files_i = *files;
	while (files_i)
	{
		if (files_i->fd == fd)
		{
			strs->line = files_i->line;
			files_i->line = NULL;
			return (0);
		}
		if (files_i->next == NULL)
		{
			if (files_init(&(files_i->next), fd) == -1)
				return (-1);
			files_i->next->prev = files_i;
			return (0);
		}
		files_i = files_i->next;
	}
	if (files_init(files, fd) == -1)
		return (-1);
	return (0);
}

void	line_saver(t_files *files, t_strings *strs, int fd)
{
	t_files	*files_i;

	files_i = files;
	while (files_i)
	{
		if (files_i->fd == fd)
		{
			if (strs->line != NULL)
			{
				files_i->line = strs->line;
				strs->line = NULL;
			}
			return ;
		}
		files_i = files_i->next;
	}
}

int	check_nl(t_strings *strs)
{
	int		i;
	char	*tmp;

	if (strs->line == NULL)
		return (0);
	i = 0;
	while (strs->line[i])
	{
		if (strs->line[i] == '\n')
		{
			strs->ret = str_dup(strs->line, i + 1);
			tmp = str_dup(&strs->line[i + 1], -1);
			free(strs->line);
			strs->line = tmp;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*cycle(t_files **files, t_strings *strs, int *read_i, int fd)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
			strs->buf[i++] = 0;
		*read_i = read(fd, strs->buf, BUFFER_SIZE);
		if (*read_i < 0)
		{
			liberator(files, fd);
			return (NULL);
		}
		strs->line = merge_str(strs);
		if (check_nl(strs) == 1)
			break ;
		if (*read_i == 0)
		{
			liberator(files, fd);
			strs->ret = str_dup(strs->line, -1);
			return (strs->ret);
		}
	}
	line_saver(*files, strs, fd);
	return (strs->ret);
}

char	*get_next_line(int fd)
{
	static t_files	*files;
	t_strings		strs;
	int				read_i;

	if (fd < 0)
		return (NULL);
	strs.buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (strs.buf == NULL)
		return (NULL);
	strs.line = NULL;
	if (check_fd(&files, &strs, fd) == -1)
		return (NULL);
	strs.ret = cycle(&files, &strs, &read_i, fd);
	if (strs.line != NULL)
		free(strs.line);
	free(strs.buf);
	return (strs.ret);
}
