#include<stdlib.h>

size_t	ft_strlen(const char *s);

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	size_t	s1len;
	size_t	s2len;
	char	*out;
	
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	len = s1len + s2len + 1;
	out = (char *)malloc(sizeof(char) * len);
	if(out == NULL)
		return (NULL);
	i = 0;
	while(i < s1len)
	{
		out[i] = s1[i];
		i++;
	}
	while(i - s1len < s2len)
	{
		out[i] = s2[i - s1len];
		i++;
	}
	out[i] = 0;
	return (out);
}