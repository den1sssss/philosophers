/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:40:25 by dshirely          #+#    #+#             */
/*   Updated: 2022/05/02 18:48:37 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_phil *phil)
{
	pthread_mutex_lock(phil->left_vilka);
	pthread_mutex_lock(phil->writem);
	printf("%ld %d has taken a fork\n", gettime(phil->table->start), phil->id);
	pthread_mutex_unlock(phil->writem);
	pthread_mutex_lock(phil->right_vilka);
	pthread_mutex_lock(phil->writem);
	printf("%ld %d has taken a fork\n%ld %d is eating\n", \
	gettime(phil->table->start), \
	phil->id, gettime(phil->table->start), phil->id);
	pthread_mutex_lock(phil->check);
	gettimeofday(&phil->last, NULL);
	pthread_mutex_unlock(phil->check);
	pthread_mutex_unlock(phil->writem);
	ft_usleep(phil->table->t_eat);
	pthread_mutex_lock(phil->writem);
	pthread_mutex_unlock(phil->left_vilka);
	pthread_mutex_unlock(phil->right_vilka);
}

void	procrastination(t_phil *phil)
{
	printf("%ld %d is sleeping\n", gettime(phil->table->start), phil->id);
	pthread_mutex_unlock(phil->writem);
	ft_usleep(phil->table->t_sleep);
	gettimeofday(&phil->current_time, NULL);
	pthread_mutex_lock(phil->writem);
	printf("%ld %d is thinking\n", gettime(phil->table->start), phil->id);
	pthread_mutex_unlock(phil->writem);
}

void	is_smb_dead(t_table *table)
{
	struct timeval	tmp;
	int				i;

	i = 0;
	while (1)
	{
		gettimeofday(&tmp, NULL);
		pthread_mutex_lock(table->philos[i].check);
		if (timeval_comp(table->philos[i].last, tmp) / 1000 > table->t_die && \
		table->philos[i].times_need_to_eat)
		{
			pthread_mutex_lock(&(table->writem));
			printf("%ld %d died\n", gettime(table->start), i + 1);
			break ;
		}
		if (table->done == table->num)
			break ;
		pthread_mutex_unlock(table->philos[i].check);
		i = (i + 1) % table->num;
	}
}

void	*routine(void *philo)
{
	t_phil	*phil;

	phil = (t_phil *)philo;
	while (phil->times_need_to_eat != 0)
	{
		eating(phil);
		procrastination(phil);
		phil->times_need_to_eat--;
	}
	phil->table->done++;
	return (NULL);
}
