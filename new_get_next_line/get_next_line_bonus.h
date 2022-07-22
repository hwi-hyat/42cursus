/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:52:05 by siykim            #+#    #+#             */
/*   Updated: 2022/07/22 17:44:19 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>

typedef struct s_files
{
	int				fd;
	char			*line;
	struct s_files	*prev;
	struct s_files	*next;
}	t_files;

typedef struct s_strings
{
	char	*buf;
	char	*line;
	char	*ret;
}	t_strings;

int		str_len(char *str);
char	*str_dup(char *str, int len);
char	*nl_attatcher(char *str);
char	*merge_str(t_strings *strs);
void	liberator(t_files **files, int fd);
char	*get_next_line(int fd);
int		files_init(t_files **node, int fd);

#endif