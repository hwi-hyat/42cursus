/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:04:04 by siykim            #+#    #+#             */
/*   Updated: 2022/07/12 02:03:52 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(t_strings *strings, int read_i)
{
	int		i;
	int		len;
	char	*tmp;

	if (strings->files_line == NULL)
	{
		if (read_i == 0)
		{
			printf("??\n");
			strings->ret_str = NULL;
			return (1);
		}
		return (0);
	}
	i = 0;
	tmp = NULL;
	len = str_len(strings->files_line);
	////printf("nl?\n");
	while (strings->files_line[i])
	{
		if (strings->files_line[i] == '\n' || read_i == 0)
		{
			if (read_i == 0)
				i = len;
			strings->ret_str = str_dup_nt2(strings->files_line, i + 1);
			tmp = str_dup_nt2(&strings->files_line[i + 1], len - i - 1);
			if (strings->files_line != NULL)
				free(strings->files_line);
			strings->files_line = tmp;
			printf("files_line is %s\npointer %p\n\n", strings->files_line, strings->files_line);
			return (1);
		}
		i++;
	}
	return (0);
}

void	search_fd(int fd, t_files *files, t_strings *strings)
{
	t_files	*files_i;

	files_i = files;
	while (files_i)
	{
		if(files_i->fd == fd)
		{
			printf("files_i->line is %s\n", files_i->line);
			strings->files_line = files_i->line;
			return ;
		}
		if (files_i->next == NULL)
		{
			files_i->next = (t_files *)malloc(sizeof(t_files));
			files_i->next->fd = fd;
			return ;
		}
		files_i = files_i->next;
	}
	files_i = (t_files *)malloc(sizeof(t_files));
	files_i->fd = fd;
}

void	fd_line_saver(t_files *files, t_strings *strings, int fd)
{
	t_files	*files_i;
	int		len;

	files_i = files;
	while (files_i)
	{
		if(files_i->fd == fd)
		{
			len = str_len(strings->files_line);
			files_i->line = str_dup_nt2(strings->files_line, len);
		}
		files_i = files_i->next;
	}
}

char	*get_next_line(int fd)
{
	static t_files	files;
	t_strings		strings;
	int				read_i;
	int				i;
	
	read_i = -1;
	strings.files_line = NULL;
	strings.tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
 	search_fd(fd, &files, &strings);
	if (fd < 3)
		return (NULL);
	////printf("%p\n", &files);
	while (1)
	{
		////printf("cycling\n");
		if (check_line(&strings, read_i) == 1 || read_i == 0)
		{
			printf("here?\n");
			fd_line_saver(&files, &strings, fd);
			free(strings.tmp);
			return (strings.ret_str);//리턴하기전에 할당해제 해줘야됨
		}
		read_i = read(fd, strings.tmp, BUFFER_SIZE);
		if (read_i < 0)
			break;
		strings.files_line = str_merger(strings.files_line, strings.tmp);
		i = 0;
		while (i < BUFFER_SIZE)
			strings.tmp[i++] = 0;
		printf("files_line is %s\n", strings.files_line);
	}
	free(strings.tmp);
	return (NULL);
}

int main()
{
	int fd;

	fd = open("./sample.txt", O_RDONLY);
	char *out;
	char in;
	for(int i = 0; i < 5; i++)
	{
		//scanf("%c", &in);
		out = get_next_line(fd);
		printf("pointer is %p\n", out);
		printf("result is %s\n", out);
	}
	close(fd);
	return 0;
}
