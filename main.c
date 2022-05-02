/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:00:34 by dshirely          #+#    #+#             */
/*   Updated: 2022/05/02 18:51:00 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parser(int argc, char **argv, t_table *table)
{
	table->num = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->times_need_to_eat = ft_atoi(argv[5]);
	}
	else if (argc == 5)
		table->times_need_to_eat = -1;
}

int	mutex_creator(t_table *table)
{
	int	i;

	table->vilki = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->num);
	if (!table->vilki)
		return (0);
	table->checks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->num);
	if (!table->checks)
		return (0);
	i = 0;
	while (i < table->num)
	{
		if (pthread_mutex_init(table->vilki + i, NULL))
			return (0);
		if (pthread_mutex_init(table->checks + i, NULL))
			return (0);
		++i;
	}
	return (1);
}

int	philo_init(t_table *table, int i)
{
	table->philos[i].table = table;
	table->philos[i].check = table->checks + i;
	table->philos[i].writem = &table->writem;
	table->philos[i].id = i + 1;
	table->philos[i].left_vilka = table->vilki + i;
	table->philos[i].times_need_to_eat = table->times_need_to_eat;
	table->philos[i].last = table->start;
	if (i != table->num - 1)
		table->philos[i].right_vilka = table->vilki + i + 1;
	else
		table->philos[i].right_vilka = table->vilki;
	if (pthread_create(&(table->philos[i].self), NULL, routine, \
	(void *)((table->philos) + i)))
		return (0);
	return (1);
}

int	philos_creator(t_table *table)
{
	int	i;

	i = 0;
	table->philos = (t_phil *)malloc(sizeof(t_phil) * table->num);
	if (!table->philos)
		return (0);
	i = 0;
	gettimeofday(&table->start, NULL);
	while (i < table->num)
	{
		philo_init(table, i);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < table->num)
	{
		philo_init(table, i);
		i += 2;
	}
	usleep(100);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (argc == 5 || argc == 6)
		parser(argc, argv, &table);
	if (ft_check_input(&table, argc))
		return (exit_error("Incorrect input!\n"));
	pthread_mutex_init(&(table.writem), NULL);
	if (!mutex_creator(&table))
		return (0);
	if (!philos_creator(&table))
		return (0);
	is_smb_dead(&table);
	ft_free(&table);
	return (0);
}
