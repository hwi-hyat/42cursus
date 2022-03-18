#include<stdlib.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (i < dstsize - 1)
	{
		if (src[i] == 0)
			break ;
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}
