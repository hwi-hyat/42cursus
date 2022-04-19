/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:18:27 by siykim            #+#    #+#             */
/*   Updated: 2022/04/20 01:37:26 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	sep_strlen(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c)
		len++;
	return (len);
}

int	word_count(char const *str, char c)
{
	int	words_cnt;

	words_cnt = 0;
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

void	placing_char(char **ans, char const *str, int words, char c)
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
		ans[i] = (char *)malloc(sizeof(char) * word_len + 1);
		j = 0;
		while (*str != c)
		{
			ans[i][j] = *str;
			str++;
			j++;
		}
		ans[i][j] = 0;
		i++;
	}
	ans[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ans;

	words = word_count(s, c);
	ans = (char **)malloc(sizeof(char *) * words + 1);
	if (ans == NULL)
		return (NULL);
	placing_char(ans, s, words, c);
	return (ans);
}
