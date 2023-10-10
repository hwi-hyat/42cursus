/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:02:29 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:40:19 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_tokenize_space_sub(t_parse_token *tok)
{
	t_parse_token	*result;
	char			**sep;
	char			*str;
	int				idx;

	sep = ft_p_split_custom(tok->string, ' ');
	if (sep == NULL || sep[0] == NULL)
		return ;
	str = ft_p_strdup(sep[0]);
	if (str == NULL)
	{
		parse_safe_free_two_d_char(sep, -1);
		return ;
	}
	free(tok->string);
	tok->string = str;
	result = tok;
	idx = 0;
	while (sep[++idx] != NULL && result != NULL)
		result = add_token(&tok, idx, TYPE_TOKEN_CHUNK, sep[idx]);
	parse_safe_free_two_d_char(sep, -1);
}

void	parse_tokenize_space_single_tok(t_parse_token *tok)
{
	char			**sep;
	int				type;
	int				index;

	sep = ft_p_strsep_custom(tok->string, ' ');
	index = -1;
	if (sep == NULL || sep[0] == NULL)
		return ;
	type = tok->token_type;
	cleanse_single_t_parse_token(tok);
	while (sep[++index] != NULL && tok != NULL)
	{
		if (sep[index][0] == ' ')
		{
			if (add_token(&tok, 1, TYPE_TOKEN_SPACE, sep[index]))
				tok = tok->next;
		}
		else
		{
			if (add_token(&tok, 1, type, sep[index]))
				tok = tok->next;
		}
	}
	parse_safe_free_two_d_char(sep, -1);
}

void	parse_tokenize_space_sep(t_parse_token *tok_lst)
{
	t_parse_token	*tok;

	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK
			&& *(tok_lst->string) == ' ')
		{
			tok = add_token(&tok_lst, 1, TYPE_TOKEN_CHUNK,
					(tok_lst->string) + 1);
			if (tok == NULL)
				return ;
			free(tok_lst->string);
			tok_lst->token_type = TYPE_TOKEN_SPACE;
			tok_lst->string = ft_p_strdup(" ");
			tok_lst = tok;
		}
		tok_lst = tok_lst->next;
	}
}

void	space(t_parse_token *tok_lst)
{
	t_parse_token	*next_tok;
	t_parse_token	*preserve;

	preserve = tok_lst;
	while (tok_lst != NULL)
	{
		next_tok = tok_lst->next;
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK)
			parse_tokenize_space_sub(tok_lst);
		tok_lst = next_tok;
	}
	parse_tokenize_space_sep(preserve);
}
