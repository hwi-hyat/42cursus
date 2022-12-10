/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:18:36 by siykim            #+#    #+#             */
/*   Updated: 2022/12/10 16:24:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	how_to_use(void)
{
	printf("./philo number_of_philosophers [time to die] [time to eat]");
	printf(" [time to sleep] [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

static int	check_minus(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_print_error(char *str)
{
	how_to_use();
	printf("%s\n", str);
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (0);
	if (check_minus(argc, argv) == 0)
		return (0);
	return (1);
}
