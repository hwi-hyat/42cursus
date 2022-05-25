/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:51:52 by siykim            #+#    #+#             */
/*   Updated: 2022/05/25 14:42:37 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_join(char *str1, char *str2)
{
	int		str1_len;
	int		str2_len;
	int		total_len;
	char	*out;

	str1_len = str_len(str1);
	str2_len = str_len(str2);
	if (str2_len == 0)
		return (str1);
	total_len = str1_len + str_len(str2);
	out = (char *)malloc(sizeof(char) * (total_len + 1));
	str_dup(out, str1);
	str_dup(&out[str1_len], str2);
	out[total_len] = 0;
	return (out);
}

char	*get_next_line(int fd)
{
	int		tmp;
	char	buf[BUFFER_SIZE];
	char	*out;

	out = 0;
	while (1)
	{
		tmp = read(fd, buf, BUFFER_SIZE);
		out = str_join(out, buf);
		if (tmp <= 0)
			break ;
	}
	return (out);
}

int main()
{
	int fd;

	fd = open("sample", 0777);
	char *out = get_next_line(fd);
	printf("%s", out);
	return 0;
}