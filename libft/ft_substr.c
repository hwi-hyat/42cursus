#include<stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	while(i < len && s[start])
	{
		out[i] = s[start];
		i++;
		start++;
	}
	out[i] = 0;
	return (out);
}