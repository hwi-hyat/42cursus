#include<stdlib.h>

char	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*cs;

	i = 0;
	cs = (char *)s;
	while (cs[i] && i < n)
	{
		if (cs[i] == c)
			return (&cs[i]);
		i++;
	}
	if (c == 0)
		return (&cs[i]);
	return (0);
}
