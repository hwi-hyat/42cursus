/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:18:27 by siykim            #+#    #+#             */
/*   Updated: 2022/04/24 15:50:01 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlen(const char *s);

int	liberate(char **ans, int i)
{
	while (i >= 0)
	{
		free(ans[i]);
		i--;
	}
	free(ans);
	return (-1);
}

int	sep_strlen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c && str[len] != 0)
		len++;
	return (len);
}

int	word_count(char *str, char c)
{
	int	words_cnt;

	words_cnt = 0;
	if (*str == 0)
		return (0);
	if (*str != c)
		words_cnt++;
	str++;
	while (*str != 0)
	{
		if (*(str - 1) == c && *str != c)
			words_cnt++;
		str++;
	}
	return (words_cnt);
}

int	placing_char(char **ans, char *str, int words, char c)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	while (i < words)
	{
		while (*str == c)
			str++;
		word_len = sep_strlen(str, c);
		ans[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (ans[i] == NULL)
			return (liberate(ans, i));
		j = 0;
		while (*str != c && *str != 0)
		{
			ans[i][j] = *str;
			str++;
			j++;
		}
		ans[i][j] = 0;
		i++;
	}
	ans[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ans;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = word_count(str, c);
	ans = (char **)malloc(sizeof(char *) * (words + 1));
	if (ans == NULL)
		return (NULL);
	if (placing_char(ans, str, words, c) == -1)
		return (NULL);
	return (ans);
}
