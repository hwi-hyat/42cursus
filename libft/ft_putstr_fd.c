#include<unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	int	length;

	if (s == NULL)
		return ;
	length = 0;
	while (1)
	{
		if (s[length] == '\0')
			break ;
		length++;
	}
	write(fd, s, length);
}