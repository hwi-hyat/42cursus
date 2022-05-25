/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:52:05 by siykim            #+#    #+#             */
/*   Updated: 2022/05/25 14:42:45 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h> // 나중에 지워주자
# include<fcntl.h> // 나중에 지워주자


# define BUFFER_SIZE 10 //나중에 지워줘야함


char	*get_next_line(int fd);
int		str_len(char *str);
void	str_dup(char *des, char *src);


#endif