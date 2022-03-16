#include<stdlib.h>

char	*strdup(const char *s)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	while (s[i] != 0)
		i++;
	out = (char *)malloc(sizeof(char) * i + 1);
	if (out == 0)
		return (0);
	j = 0;
	while (j != i)
	{
		out[j] = s[j];
		j++;
	}
	out[j] = '\0';
	return (out);
}
