#include<stdlib.h>

size_t	ft_strlen(const char *s);

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int 	i;

	i = 0;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}