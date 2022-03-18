#include<unistd.h>

void ft_putendl_fd(char *s, int fd)
{
	int	length;

	length = 0;
	while (1)
	{
		if (s[length] == '\0')
			break ;
		length++;
	}
	write(fd, s, length);
	write(fd, "\n", 1);
}