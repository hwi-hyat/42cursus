/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 01:45:42 by siykim            #+#    #+#             */
/*   Updated: 2022/05/25 14:31:44 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	str_dup(char *des, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		des[i] = src[i];
		i++;
	}
}