#include<stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (i < n)
	{	
		if (cs1[i] - cs2[i] != 0)
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
