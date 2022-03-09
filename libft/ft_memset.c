#include<stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*cb;

	cb = b;
	i = 0;
	while (i < len && b[i])
	{
		cb[i] = (unsigned char)c;
		i++;
	}
}