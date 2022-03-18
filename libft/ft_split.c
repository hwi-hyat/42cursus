#include<stdlib.h>

int	sep(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

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
		if (sep(s[i], c) == 0)
			flag = 1;
		if (flag && (sep(s[i + 1], c) == 1 || s[i + 1] == 0))
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
	while (sep(str[i], c) == 0 && str[i] != 0)
		i++;
	return (i);
}

void	filler05(char **out, char const *s, char c, int wi)
{
	int	i;

	i = 0;
	while (sep(s[i], c) == 0 && s[i] != 0)
		i++;
	out[wi] = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (sep(s[i], c) != 1 && s[i] != 0)
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
		if (sep(s[i], c) == 0)
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