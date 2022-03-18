#include<stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*out;
	size_t	i;

	out = (char *)malloc(size * nmemb);
	//이렇게 해도 될까? 1바이트씩 초기화 해줄려고 캐릭터포인터로 받았는데
	//size가 0일때도 생각을 해줘야겠는데??
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		out[i] = 0;
		i++;
	}
	return ((void *)out);
}
