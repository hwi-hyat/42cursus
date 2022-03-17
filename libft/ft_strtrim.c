#include<stdlib.h>

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

int len_check(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s1[i])
	{
		if (!is_it_set(set, s1[i]))
			len++;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		ii;
	int		trimmedlen;
	char	*out;

	i = 0;
	ii = 0;
	trimmedlen = len_check(s1, set);
	out = (char *)malloc(sizeof(char) * (trimmedlen + 1));
	if (out == NULL)
		return (NULL);
	while (s1[i])
	{
		if (!is_it_set(set, s1[i]))
		{	
			out[ii] = s1[i];
			ii++;
		}
		i++;
	}
	out[ii] = 0;
	return (out);
}