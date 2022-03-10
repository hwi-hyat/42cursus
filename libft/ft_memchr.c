#include<stdlib.h>

char	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;
	//char *cs;

	i = 0;
	//cs = s;
	while (((char *)s)[i])
	{
		if (((char *)s)[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}