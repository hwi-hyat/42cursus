/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:04:52 by jeounpar          #+#    #+#             */
/*   Updated: 2022/11/10 21:20:46 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_alloc(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i += 1;
	}
	free(str);
}

void	ft_errors(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_nullexeption(char **voca)
{
	free_alloc(voca);
	return (0);
}
