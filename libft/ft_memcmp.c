#include<stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char *cs1;
	char *cs2;

	i = 0;
	cs1 = (char *)s1;
	cs2 = (char *)s2;
	while (i < n)
	{	
		if (cs1[i] - cs2[i] != 0)
			return (cs1[i] - cs2[i]);
		if (cs1[i] == '\0' || cs2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
