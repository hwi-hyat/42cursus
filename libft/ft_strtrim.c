#include<stdlib.h>

size_t	ft_strlen(const char *s);

int is_it_set(char const *set, char c)
{
	int	i;

	i = 0;
	while(set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		bi;
	int		len;
	char	*out;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (is_it_set(set, s1[i]))
		i++;
	len = ft_strlen(&s1[i]);
	if (i == len)
		return (NULL);
	bi = 0;
	while (is_it_set(set, s1[len + i - bi - 1]))
		bi++;
	len -= bi;
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	out[len] = 0;
	bi = 0;
	while (bi < len)
	{
		out[bi] = s1[i + bi];
		bi++;
	}
	return (out);
}