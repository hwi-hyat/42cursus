/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:16:30 by siykim            #+#    #+#             */
/*   Updated: 2022/07/17 22:12:02 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_fd(t_files **files, t_strings *strs, int fd)
{
	t_files	*files_i;

	files_i = *files;
	while (files_i)
	{
		////printf("where1?\n");
		////printf("fd of list is %d\n", files_i->fd);
		if (files_i->fd == fd)
		{
			////printf("where2?\n");
			strs->line = files_i->line;
			files_i->line = 0;
			return ;
		}
		if(files_i->next == NULL)
		{
			////printf("where3?\n");
			files_i->next = (t_files *)malloc(sizeof(t_files));
			files_i->next->fd = fd;
			files_i->next->prev = files_i;
			return ;
		}
		files_i = files_i->next;
	}
	(*files) = (t_files *)malloc(sizeof(t_files));
	////printf("files is %p\n", files);
	(*files)->fd = fd;
	(*files)->next = NULL;
	(*files)->prev = NULL;
}

void	line_saver(t_files *files, char *line, int fd)
{
	t_files	*files_i;

	files_i = files;
	while(files_i)
	{
		if (files_i->fd == fd)
		{
			//printf("saving %s\n", line);
			if (line != NULL)
			{
				files_i->line = str_dup(line, -1);
				free(line);
				line = NULL;
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
			//printf("gogo tmp\n");
			tmp = str_dup(&strs->line[i + 1], -1);
			//strs->line[i + 1]에서?? 여기맞는데
			free(strs->line);
			strs->line = tmp;
			//printf("trimmed line is %s\n", strs->line);
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
	
	read_i = -1;
	if (fd < 3)
		return (NULL);
	strs.buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	strs.line = NULL;
	check_fd(&files, &strs, fd);
	//printf("line is %s\n", strs.line);
	while(1)
	{
		//printf("line is %s, buf is %s\n", strs.line, strs.buf);
		if (check_nl(&strs) == 1)
		{
			line_saver(files, strs.line, fd);
			free(strs.buf);
			return (strs.ret);
		}
		else if (read_i == 0)
		{
			liberator(&files, fd);
			free(strs.buf);
			return (strs.line);
		}
		i = 0;
		while (i <= BUFFER_SIZE)
			strs.buf[i++] = 0;
		read_i = read(fd, strs.buf, BUFFER_SIZE);
		//////printf("read_i is %d\n", read_i);
		if (read_i < 0)
			break ;
		//printf("line is %s, buf is %s\n", strs.line, strs.buf);
		strs.line = merge_str(&strs);
		//printf("line is %s, buf is %s\n", strs.line, strs.buf);
	}
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
	char in;
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