/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 01:45:42 by siykim            #+#    #+#             */
/*   Updated: 2022/07/13 18:24:39 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(char *str)
{
	int	len;

	if(str == 0)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	str_cpy(char *des, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		des[i] = src[i];
		i++;
	}
}

char *nl_adder(char *str)
{
	int		len;
	char	*tmp;
	
	if (str == NULL)
		return (NULL);
	len = str_len(str);
	tmp = (char *)malloc(sizeof(char) * (len + 2));
	str_cpy(tmp, str, len);
	tmp[len] = '\n';
	tmp[len + 1] = 0;
	free(str);
	return (tmp);
}

char	*str_dup_nt2(char *src, int len)
{
	char *des;

	if (len <= 1)
		return (NULL);
	des = (char *)malloc(sizeof(char) * (len + 1));
	str_cpy(des, src, len);
	des[len] = 0;
	//printf("des is %p str %s\n", des, des);
	return (des);
}

char	*str_merger(char *des, char *src)
{
	int		deslen;
	int		srclen;
	char	*out;

	deslen = str_len(des);
	srclen = str_len(src);
	if (srclen == 0)
		return (des);
	out = (char *)malloc(sizeof(char) * (deslen + srclen + 1));
	str_cpy(out, des, deslen);
	str_cpy(&out[deslen], src, srclen);
	out[deslen + srclen] = 0;
	if (deslen != 0)
		free(des);
	return (out);
}
