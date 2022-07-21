/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:16:30 by siykim            #+#    #+#             */
/*   Updated: 2022/07/21 13:12:07 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	check_fd(t_files **files, t_strings *strs, int fd)
{
	t_files	*files_i;

	files_i = *files;
	while (files_i)
	{
		if (files_i->fd == fd)
		{
			strs->line = files_i->line;
			files_i->line = NULL;
			return ;
		}
		if (files_i->next == NULL)
		{
			files_i->next = (t_files *)malloc(sizeof(t_files));
			files_i->next->fd = fd;
			files_i->next->line = NULL;
			files_i->next->next = NULL;
			files_i->next->prev = files_i;
			return ;
		}
		files_i = files_i->next;
	}
	(*files) = (t_files *)malloc(sizeof(t_files));
	(*files)->fd = fd;
	(*files)->line = NULL;
	(*files)->next = NULL;
	(*files)->prev = NULL;
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

char	*get_next_line(int fd)
{
	static t_files	*files;
	t_strings		strs;
	int				read_i;
	int				i;

	if (fd < 0)
		return (NULL);
	strs.buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	strs.line = NULL;
	check_fd(&files, &strs, fd);
	while (1)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
			strs.buf[i++] = 0;
		read_i = read(fd, strs.buf, BUFFER_SIZE);
		if (read_i < 0)
			break ;
		strs.line = merge_str(&strs);
		if (check_nl(&strs) == 1)
		{
			line_saver(files, &strs, fd);
			free(strs.buf);
			return (strs.ret);
		}
		if (read_i == 0)
		{
			liberator(&files, fd);
			free(strs.buf);
			return (strs.line);
		}
	}
	if (strs.line != NULL)
		free(strs.line);
	liberator(&files, fd);
	free(strs.buf);
	return (NULL);
}
/*
int main()
{
	int fd;

	fd = open("./sample.txt", O_RDONLY);
	char *out;
	//char in;
	for(int i = 0; i < 10; i++)
	{
		printf("\n----------------------------------\n");
		out = get_next_line(fd);
		////////////printf("pointer is %p\n", out);
		printf("result is %s\n", out);
		printf("----------------------------------\n");
	}
	close(fd);
	system("leaks a.out");
	return 0;
}
*/