#include<stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*cb;

	cb = (char *)b;
	i = 0;
	while (i < len && cb[i])
	{
		cb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}