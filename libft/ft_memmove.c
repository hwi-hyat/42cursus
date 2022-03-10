#include<stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int		i;
	char				*cdst;
	char				*csrc;
	char				temp;

	cdst = dst;
	csrc = src;
	i = 0;
	while(i < len)
	{
		temp = csrc[i];
		cdst[i] = temp;
		i++;
	}
}