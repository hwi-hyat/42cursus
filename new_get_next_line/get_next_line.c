/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:16:30 by siykim            #+#    #+#             */
/*   Updated: 2022/07/15 13:54:20 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_fd(t_files *files, t_strings *strs, int fd)
{
	t_files	*files_i;

	files_i = files;
	while (files_i)
	{
		if (files_i->fd == fd && (files_i->line != NULL))
		{
			printf("files->line is %s\n", files_i->line);
			strs->line = files_i->line;
			files_i->line = 0;
			return ;
		}
		if(files_i->next == NULL)
		{
			files_i->next = (t_files *)malloc(sizeof(t_files));
			files_i->next->fd = fd;
			files_i->next->prev = files_i;
			return ;
		}
		files_i = files_i->next;
	}
	files_i = (t_files *)malloc(sizeof(t_files));
	files_i->fd = fd;
}

void	line_saver(t_files *files, char *line, int fd)
{
	t_files	*files_i;

	files_i = files;
	while(files_i)
	{
		if (files_i->fd == fd)
		{
			files_i->line = line;
			line = 0;
			return ;
		}
		files_i = files_i->next;
	}
}

int	check_nl(char *line, t_strings *strs, t_files *files)
{
	int		i;
	char	*tmp;

	if (line == NULL)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			strs->ret = str_dup(line, i + 1);
			tmp = str_dup(&line[i + 1], -1);
			//free(line);
			line = tmp;
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
	
	if (fd < 3)
		return (NULL);
	strs.buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	strs.line = NULL;
	check_fd(files, &strs, fd);
	printf("saved line was %s\n", strs.line);
	while(1)
	{
		if (check_nl(strs.line, &strs, files) == 1)
		{
			line_saver(files, strs.line, fd);
			free(strs.buf);
			return (strs.ret);
		}
		else if (read_i == 0)
		{
			free(strs.buf);
			return (strs.line);
		}
		i = 0;
		while (i <= BUFFER_SIZE)
			strs.buf[i++] = 0;
		read_i = read(fd, strs.buf, BUFFER_SIZE);
		strs.buf[read_i] = 0;
		if (read_i < 0)
			break ;
		strs.line = merge_str(strs.line, strs.buf);
		printf("line is %s, buf is %s\n", strs.line, strs.buf);
	}
	free(strs.buf);
	return (NULL);
}

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
		////printf("pointer is %p\n", out);
		printf("result is %s\n", out);
		printf("----------------------------------\n");
	}
	close(fd);
	system("leaks a.out");
	return 0;
}
