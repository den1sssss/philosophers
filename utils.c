/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:59:17 by dshirely          #+#    #+#             */
/*   Updated: 2022/05/02 18:51:09 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (0);
}

void	ft_free(t_table *table)
{
	free(table->checks);
	free(table->vilki);
	free(table->philos);
}

int	ft_check_input(t_table *table, int argc)
{
	if (argc == 5)
	{
		if (table->num < 1 || table->t_die < 1 || table->t_eat < 1 || \
			table->t_sleep < 1)
		{
			printf("Check your input!\n");
			return (1);
		}	
	}
	if (argc == 6)
	{
		if (table->num < 1 || table->t_die < 1 || table->t_eat < 1 || \
			table->t_sleep < 1 || table->times_need_to_eat < 1)
		{
			printf("Check your input!\n");
			return (1);
		}
	}
	if (argc < 5 || argc > 6)
	{
		printf("Check your input!\n");
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	unsigned long long	sum;

	sum = 0;
	if (*str == '+')
		str++;
	if (*str == '0')
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (sum > 2147483647)
		return (-1);
	if (sum > 2147483648)
		return (0);
	return ((int)sum);
}
