#include<stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*cdst;
	unsigned char		*csrc;

	if (dst == 0 && src == 0)
		return (0);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	len -= 1;
	if (dst < src)
		while (i <= len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	else if (src < dst)
		while (len >= 0)
		{
			cdst[len] = csrc[len];
			len--;
		}
	return (dst);
}
//오버랩 발생하면 따로 저장해주도록 돌아가게 고쳐야될거같음.
//두 메모리 주소 차 랑 len이랑 비교해서 오버랩 판단할수있을듯