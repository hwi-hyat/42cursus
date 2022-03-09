#include<stdlib.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned long		i;
	char				*cdst;
	char				*csrc;

	cdst = dst;
	csrc = src;
	i = 0;
	while(i < n && cdst[i] && csrc[i])
	{
		cdst[i] = csrc[i];
		i++;
	}
}