#include "get_next_line.h"


void search_fd(int fd, t_files *files, s_strings strings)
{
	t_files	*files_i;

	files_i = files;
	while(files_i)
}

char	*get_next_line(int fd)
{
	static t_files	*files;
	s_strings		strings;

	read(fd, strings.tmp, BUFFER_SIZE);
	



}