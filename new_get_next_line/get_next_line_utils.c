/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:19:35 by siykim            #+#    #+#             */
/*   Updated: 2022/07/17 22:36:06 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while(str[len])
		len++;
	return (len);
}

void	str_cpy(char *des, char *src)
{
	int	i;

	i = 0;
	if (src == NULL)
		return ;
	while (src[i])
	{
		des[i] = src[i];
		i++;
	}
}

char	*str_dup(char *str, int len)
{
	int		i;
	char	*out;

	if (len == -1)
		len = str_len(str);
	//printf("len is %d\n", len);
	if (len == 0)
		return (NULL);
	out = (char *)malloc(sizeof(char) * (len + 1));
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

	len_line = str_len(strs->line);
	len_buf = str_len(strs->buf);
	if (len_buf == 0)
		return (strs->line);
	tmp = (char *)malloc(sizeof(char) * (len_line + len_buf + 1));
	str_cpy(tmp, strs->line);
	str_cpy(&tmp[len_line], strs->buf);
	tmp[len_line + len_buf] = 0;
	free(strs->line);
	strs->line = NULL;
	return(tmp);
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
				*files = files_i->next;
			else
				files_i->prev->next = files_i->next;
			free(files_i);
			return ;
		}
		files_i = files_i->next;
	}
}