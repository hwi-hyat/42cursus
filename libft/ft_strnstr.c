#include<stdlib.h>

int	comparer(char *str, char *to_find, int to_find_len)
{
	int	i;

	i = 0;
	while (i < to_find_len)
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

int	length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (length(to_find) == 0)
		return (str);
	while (i < length(str))
	{
		if (str[i] == to_find[0])
		{
			if (comparer(&str[i], to_find, length(to_find)) == 1)
				return (&str[i]);
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	return (0);
}