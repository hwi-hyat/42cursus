/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:52:05 by siykim            #+#    #+#             */
/*   Updated: 2022/07/12 01:38:52 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h> // 나중에 지워주자
# include<fcntl.h> // 나중에 지워주자

//# define BUFFER_SIZE 1 //나중에 지워줘야함

typedef struct s_files
{
	int				fd;
	char			*line;
	struct s_files	*next;
} t_files;

typedef struct s_strings
{
	char	*tmp;
	char	*files_line;
	char	*ret_str;
} t_strings;





char	*get_next_line(int fd);
int		str_len(char *str);
void	str_cpy(char *des, char *src, int len);
void	str_dup_nt(char *des, char *src, int len);
char	*str_dup_nt2(char *src, int len);
char	*str_merger(char *des, char *src);
char	 *nl_adder(char *str);


#endif