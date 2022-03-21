#include<stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if (c == 0)
		return (&((char *)s)[size]);
	while (size)
	{
		size--;
		if (s[size] == c)
			return (&((char *)s)[size]);
	}
	return (0);
}
