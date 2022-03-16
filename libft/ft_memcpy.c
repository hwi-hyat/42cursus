#include<stdlib.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned long		i;

	i = 0;
	while (i < n && ((char *)dst)[i] && ((char *)src)[i])
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
