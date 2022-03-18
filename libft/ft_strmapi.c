#include<stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int 	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if(out == 0)
		return (0);
	while(i < len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}