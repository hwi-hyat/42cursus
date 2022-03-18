#include<stdlib.h>

size_t	ft_strlen(const char *s);

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int 	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	while(i < len)
	{
		f(i, &s[i]);
		i++;
	}
}