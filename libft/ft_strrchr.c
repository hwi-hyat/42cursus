#include<stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	size;

	size = ft_strlen(s) - 1;
	while (size >= 0)
	{
		if (s[size] == c)
			return (&s[size]);
		size--;
	}
	return (0);
}