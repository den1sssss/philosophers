#include "philo.h"
long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}

int	timeval_comp(struct timeval fst, struct timeval snd)
{
	return ((snd.tv_sec - fst.tv_sec) * 1000000 + snd.tv_usec - fst.tv_usec);

}
void is_smb_dead(t_table *table)
{
	struct timeval	tmp;
	int				i;

	i = 0;
	while (1)
	{
		gettimeofday(&tmp, NULL);
		pthread_mutex_lock(table->philos[i].check);
		if (timeval_comp(table->philos[i].last, tmp) / 1000 > table->t_die \
		&& table->philos[i].times_need_to_eat)
		{
			pthread_mutex_lock(&(table->writem));
			printf("%d %d died\n", timeval_comp(table->start, tmp) \
			/ 1000, i + 1);
			break ;
		}
		if (table->done == table->num)
			break ;
		pthread_mutex_unlock(table->philos[i].check);
		i = (i + 1) % table->num;
	}
}

void ft_sleep(t_phil *phil, int milisec)
{
	struct timeval temp;
	
	gettimeofday(&temp, NULL);
	while (timeval_comp(phil->current_time, temp) < milisec * 1000)
	{
		usleep(20);
		gettimeofday(&temp, NULL);
	}
}

void eating_process(t_phil *phil)
{
	pthread_mutex_lock(phil->left_vilka);
	pthread_mutex_lock(phil->writem);
	gettimeofday(&phil->current_time,NULL);
	printf("%ld %d has taken a fork\n",ft_time() - phil->start_time,phil->id);
	pthread_mutex_unlock(phil->writem);
	pthread_mutex_lock(phil->right_vilka);	
	pthread_mutex_lock(phil->writem);
	gettimeofday(&phil->current_time,NULL);
	printf("%ld %d has taken a fork\n%ld %d is eating\n",ft_time() - phil->start_time, \
	     phil->id,ft_time() - phil->start_time, phil->id );
	pthread_mutex_lock(phil->check);
	gettimeofday(&phil->last,NULL);
	pthread_mutex_unlock(phil->check);
	pthread_mutex_unlock(phil->writem);
	ft_sleep(phil,phil->table->t_eat);
	pthread_mutex_lock(phil->writem);
	pthread_mutex_unlock(phil->left_vilka);
	pthread_mutex_unlock(phil->right_vilka);
}

void procrastination(t_phil *phil)
{
	gettimeofday(&phil->current_time,NULL);
	printf("%ld %d is sleeping\n",ft_time() - phil->start_time,phil->id);
	pthread_mutex_unlock(phil->writem);
	ft_sleep(phil,phil->table->t_sleep);
	pthread_mutex_lock(phil->writem);
	gettimeofday(&phil->current_time,NULL);
	printf("%ld %d is thinking\n",ft_time() - phil->start_time,phil->id);
	pthread_mutex_unlock(phil->writem);
}

void	*routine(void *philo)
{
	t_phil *phil;

	phil=(t_phil *)philo;
	phil->start_time = ft_time();
	while(phil->times_need_to_eat != 0)
	{
		eating_process(phil);
		procrastination(phil);
		phil->times_need_to_eat--;
	}
	if(phil->times_need_to_eat == 0)
		printf("%d philosophers have eaten the required number of times!\n",timeval_comp(phil->table->start,phil->current_time) / 1000);
	phil->table->done++;
	return (NULL);
}