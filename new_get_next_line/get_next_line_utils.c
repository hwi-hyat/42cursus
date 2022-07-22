/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:19:35 by siykim            #+#    #+#             */
/*   Updated: 2022/07/22 17:44:41 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*str_dup(char *str, int len)
{
	int		i;
	char	*out;

	if (len == -1)
		len = str_len(str);
	if (len == 0)
		return (NULL);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

char	*merge_str(t_strings *strs)
{
	int		len_line;
	int		len_buf;
	char	*tmp;
	int		i;

	len_line = str_len(strs->line);
	len_buf = str_len(strs->buf);
	if (len_buf == 0)
		return (strs->line);
	tmp = (char *)malloc(sizeof(char) * (len_line + len_buf + 1));
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (strs->line && strs->line[++i])
		tmp[i] = strs->line[i];
	i = -1;
	while (strs->buf && strs->buf[++i])
		tmp[len_line + i] = strs->buf[i];
	tmp[len_line + len_buf] = 0;
	if (strs->line != NULL)
		free(strs->line);
	strs->line = NULL;
	return (tmp);
}

void	liberator(t_files **files, int fd)
{
	t_files	*files_i;

	files_i = *files;
	while (files_i)
	{
		if (files_i->fd == fd)
		{
			if (files_i->prev == NULL)
			{
				*files = files_i->next;
				if (files_i->next != NULL)
					files_i->next->prev = NULL;
			}
			else
			{
				files_i->prev->next = files_i->next;
				if (files_i->next != NULL)
					files_i->next->prev = files_i->prev;
			}
			free(files_i);
			return ;
		}
		files_i = files_i->next;
	}
}

int	files_init(t_files **node, int fd)
{
	*node = (t_files *)malloc(sizeof(t_files));
	if (*node == NULL)
		return (-1);
	(*node)->fd = fd;
	(*node)->line = NULL;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	return (0);
}
