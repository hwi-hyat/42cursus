/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:35:29 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 21:15:30 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_ok(char c, char set)
{
	if (c == '\0' || c == set)
		return (1);
	return (0);
}

int	cnt_word(char *str, char set)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (is_ok(str[i], set)))
			i++;
		if (str[i] != '\0' && !(is_ok(str[i], set)))
		{
			cnt++;
			while (str[i] != '\0' && !(is_ok(str[i], set)))
				i++;
		}
	}
	return (cnt);
}

static int	words_malloc(char *str, char set, char **words)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	while (str[i] != '\0')
	{
		if (!is_ok(str[i], set))
		{
			j++;
			if (is_ok(str[i + 1], set))
			{
				words[idx] = (char *)malloc((j + 1) * sizeof(char));
				if (words[idx] == NULL)
					return (0);
				idx++;
				j = 0;
			}
		}
		i++;
	}
	return (1);
}

static void	wr_words(char *str, char set, char **words)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	while (str[i] != '\0')
	{
		if (!is_ok(str[i], set))
		{
			words[idx][j] = str[i];
			j++;
			if (is_ok(str[i + 1], set))
			{
				words[idx][j] = '\0';
				idx++;
				j = 0;
			}
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	int		i;
	char	*str;
	char	**words;

	str = (char *)s;
	cnt = cnt_word(str, c);
	words = (char **)malloc((cnt + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	if (words_malloc(str, c, words) == 0)
	{
		i = 0;
		while (words[i])
		{
			free(words[i]);
			i++;
		}
		free(words);
		return (NULL);
	}
	wr_words(str, c, words);
	words[cnt] = NULL;
	return (words);
}
