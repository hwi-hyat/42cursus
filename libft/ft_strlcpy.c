#include<stdlib.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1)
	{
		if (src[i] == 0)
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
