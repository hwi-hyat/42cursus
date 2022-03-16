#include<stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	size;

	size = ft_strlen(s) - 1;
	while (1)
	{
		if (s[size] == c)
			return (&((char *)s)[size]);
		else if (size == 0)
			break ;
		size--;
	}
	return (0);
}
