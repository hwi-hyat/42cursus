#include<stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

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
	bi = 0;
	len = ft_strlen(s1);
	while (is_it_set(set, s1[i]))
		i++;
	while (is_it_set(set, s1[len - 1]) && len > i)
		len--;
	out = (char *)malloc((len - i + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while ((i + bi) < len)
	{
		out[bi] = s1[i + bi];
		bi++;
	}
	out[bi] = 0;
	return (out);
}