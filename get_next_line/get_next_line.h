/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:52:05 by siykim            #+#    #+#             */
/*   Updated: 2022/05/30 01:07:28 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h> // 나중에 지워주자
# include<fcntl.h> // 나중에 지워주자

# define BUFFER_SIZE 10 //나중에 지워줘야함

typedef struct s_files
{
	int		fd;
	char	*line;
	t_files	*next;
}t_files;

typedef struct s_strings
{
	char	*tmp;
	char	*files_str;
	char	*ret_str;
}s_strings;





char	*get_next_line(int fd);
int		str_len(char *str);
void	str_cpy(char *des, char *src, int len);


#endif