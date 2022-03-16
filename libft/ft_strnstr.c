#include<stdlib.h>

size_t	ft_strlen(const char *s);

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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len - ft_strlen(needle))
	{
		if (haystack[i] == needle[0])
		{
			if (comparer(&((char *)haystack)[i], (char *)needle, ft_strlen(needle)) == 1)
				return (&((char *)haystack)[i]);
			if (((char *)haystack)[i] == '\0')
				break ;
		}
		i++;
	}
	return (0);
}