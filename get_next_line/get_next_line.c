/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:51:52 by siykim            #+#    #+#             */
/*   Updated: 2022/05/30 01:11:13 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_join(char *str1, char *str2, int str2_len)
{
	int		str1_len;
	int		total_len;
	char	*out;
	
	if (str1 == 0)
		str1_len = 0;
	else
		str1_len = str_len(str1);
	total_len = str1_len + str2_len;
	out = (char *)malloc(sizeof(char) * (total_len + 1));
	str_cpy(out, str1, str1_len);
	str_cpy(&out[str1_len], str2, str2_len);
	out[total_len] = 0;
	free(str1);
	return (out);
}

int nl_check(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	int		tmp;
	int		len;
	char	buf[BUFFER_SIZE];
	char	*out;

	out = 0;
	while (1)
	{
		tmp = read(fd, buf, BUFFER_SIZE);
		if (tmp <= 0)
			break ;
		len = nl_check(buf);
		out = str_join(out, buf, len);
		if (len < BUFFER_SIZE)
			break ;
	}
	return (out);
}
/*
int main()
{
	int fd;

	fd = open("sample", O_RDWR);
	char *out = get_next_line(fd);
	printf("%s", out);
	close(fd);
	return 0;
}
*/