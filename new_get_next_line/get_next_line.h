/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:52:05 by siykim            #+#    #+#             */
/*   Updated: 2022/07/15 18:07:50 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h> // 나중에 지워주자
# include<fcntl.h> // 나중에 지워주자

# define BUFFER_SIZE 11 //나중에 지워줘야함

typedef struct s_files
{
	int				fd;
	char			*line;
	struct s_files	*prev;
	struct s_files	*next;
} t_files;

typedef struct s_strings
{
	char	*buf;
	char	*line;
	char	*ret;
} t_strings;

int		str_len(char *str);
char	*str_dup(char *str, int len);
char	*nl_attatcher(char *str);
char	*merge_str(char *line, char *buf);
char	*get_next_line(int fd);
void	liberator(t_files **files, int fd);

#endif