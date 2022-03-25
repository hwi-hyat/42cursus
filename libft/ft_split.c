#include<stdlib.h>

int	word_counter(char const *s, char c)
{
	int	i;
	int	flag;
	int	cnt;

	i = 0;
	flag = 0;
	cnt = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
			flag = 1;
		if (flag && (s[i + 1] == c || s[i + 1] == 0))
		{
			cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

int	len_cnt(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != 0)
		i++;
	return (i);
}

void	filler05(char **out, char const *s, char c, int wi)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	out[wi] = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		out[wi][i] = s[i];
		i++;
	}
	out[wi][i] = 0;
}

char **ft_split(char const *s, char c)
{
	int		i;
	int		words;
	int		wi;
	char	**out;

	i = 0;
	wi = 0;
	words = word_counter(s, c);
	out = (char **)malloc(sizeof(char *) * (words + 1));
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			filler05(out, &s[i], c, wi);
			wi++;
			i += len_cnt(&((char *)s)[i], c);
		}
		i++;
	}
	out[wi] = NULL;
	return (out);
}