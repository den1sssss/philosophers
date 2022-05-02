#include "philo.h"
// int	timeval_comp(struct timeval fst, struct timeval snd)
// {
// 	// return ((snd.tv_sec - fst.tv_sec) * 1000000 + snd.tv_usec - fst.tv_usec);
// 	return (snd.tv_usec - fst.tv_usec + (snd.tv_sec - fst.tv_sec) * 1000000);
// }
// void is_smb_dead(t_table *table)
// {
// 	struct timeval	tmp;
// 	int				i;

// 	i = 0;
// 	while (1)
// 	{
// 		gettimeofday(&tmp, NULL);
// 		pthread_mutex_lock(table->philos[i].check);
// 		if (timeval_comp(table->philos[i].last, tmp) / 1000 > table->t_die \
// 		&& table->philos[i].times_need_to_eat)
// 		{
// 			pthread_mutex_lock(&(table->writem));
// 			printf("%d %d died\n", timeval_comp(table->start, tmp) \
// 			/ 1000, i + 1);
// 			break ;
// 		}
// 		if (table->done == table->num)
// 			break ;
// 		pthread_mutex_unlock(table->philos[i].check);
// 		i = (i + 1) % table->num;
// 	}
// }

// void ft_sleep(t_phil *phil, int milisec)
// {
// 	struct timeval temp;
	
// 	gettimeofday(&temp, NULL);
// 	while (timeval_comp(phil->current_time, temp) < milisec * 1000)
// 	{
// 		usleep(20);
// 		gettimeofday(&temp, NULL);
// 	}
// }

// void eating_process(t_phil *phil)
// {
// 	pthread_mutex_lock(phil->left_vilka);
// 	pthread_mutex_lock(phil->writem);
// 	gettimeofday(&phil->current_time,NULL);
// 	printf("%d %d has taken a fork\n",timeval_comp(phil->table->start,phil->current_time) / 1000,phil->id);
// 	pthread_mutex_unlock(phil->writem);
// 	pthread_mutex_lock(phil->right_vilka);	
// 	pthread_mutex_lock(phil->writem);
// 	gettimeofday(&phil->current_time,NULL);
// 	printf("%d %d has taken a fork\n%d %d is eating\n",timeval_comp(phil->table->start,phil->current_time) / 1000, \
// 	     phil->id,timeval_comp(phil->table->start,phil->current_time) / 1000, phil->id );
// 	pthread_mutex_lock(phil->check);
// 	gettimeofday(&phil->last,NULL);
// 	pthread_mutex_unlock(phil->check);
// 	pthread_mutex_unlock(phil->writem);
// 	ft_sleep(phil,phil->table->t_eat);
// 	pthread_mutex_lock(phil->writem);
// 	pthread_mutex_unlock(phil->left_vilka);
// 	pthread_mutex_unlock(phil->right_vilka);
// }

// void procrastination(t_phil *phil)
// {
// 	gettimeofday(&phil->current_time,NULL);
// 	printf("%d %d is sleeping\n",timeval_comp(phil->table->start,phil->current_time) / 1000,phil->id);
// 	pthread_mutex_unlock(phil->writem);
// 	ft_sleep(phil,phil->table->t_sleep);
// 	gettimeofday(&phil->current_time,NULL);
// 	pthread_mutex_lock(phil->writem);
// 	printf("%d %d is thinking\n",timeval_comp(phil->table->start,phil->current_time) / 1000,phil->id);
// 	pthread_mutex_unlock(phil->writem);
// }

// void	*routine(void *philo)
// {
// 	t_phil *phil;

// 	phil=(t_phil *)philo;
// 	while(phil->times_need_to_eat != 0)
// 	{
// 		eating_process(phil);
// 		procrastination(phil);
// 		phil->times_need_to_eat--;
// 	}
// 	phil->table->done++;
// 	// if(phil->times_need_to_eat == 0)
// 	// 	printf("%d philosophers have eaten the required number of times!\n",timeval_comp(phil->table->start,phil->current_time) / 1000);
// 	return (NULL);
// }





//---------------------------------------------------------------------------------------------------------------2
// long int	gettime(long int *time)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	if (time)
// 		*time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
// 	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }

// long	timeval_comp(struct timeval start) // tekuwee vremya kotoroe vivoditsya // dlya eating sleeping etc.
// {
// 	struct timeval	tv;
// 	long			res;

// 	gettimeofday(&tv, NULL);
// 	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000 ;
// 	res-=1000 * (size_t)start.tv_sec + (size_t)start.tv_usec / 1000;
// 	return (res);
// }
// long	cur_time(struct timeval fst) // dlya is_smb_dead i ft_sleep
// {
// 	struct timeval	tv;
// 	// long			res;

// 	gettimeofday(&tv, NULL);
// 	return (tv.tv_usec - fst.tv_usec + (tv.tv_sec - fst.tv_sec) * 1000000);
// }
// void is_smb_dead(t_table *table)
// {
// 	// struct timeval	tmp;
// 	int				i;

// 	i = 0;
// 	while (1)
// 	{
// 		// gettimeofday(&tmp, NULL);
// 		pthread_mutex_lock(table->philos[i].check);
// 		if (cur_time(table->philos[i].last)> table->t_die \
// 		&& table->philos[i].times_need_to_eat)
// 		{
// 			pthread_mutex_lock(&(table->writem));
// 			printf("%ld %d died\n", timeval_comp(table->start) \
// 			, i + 1);
// 			break ;
// 		}
// 		if (table->done == table->num)
// 			break ;
// 		pthread_mutex_unlock(table->philos[i].check);
// 		i = (i + 1) % table->num;
// 	}
// }

// void ft_sleep(t_phil *phil, int milisec)
// {
// 	// struct timeval temp;
	
// 	// gettimeofday(&temp, NULL);
// 	// while (cur_time(phil->current_time) < milisec)
// 	// {
// 	// 	usleep(20);
// 	// 	// gettimeofday(&temp, NULL);
// 	// }
// 	// long	time;

// 	// time = timeval_comp(phil->table->start);
// 	// usleep(ms * 920);
// 	// while (ft_time() < time + ms)
// 	// 	usleep(ms * 3);

// 	struct timeval temp;
	
// 	gettimeofday(&temp, NULL);
// 	while (timeval_comp(phil->current_time, temp) < milisec * 1000)
// 	{
// 		usleep(20);
// 		gettimeofday(&temp, NULL);
// 	}
// }

// void eating_process(t_phil *phil)
// {
// 	pthread_mutex_lock(phil->left_vilka);
// 	pthread_mutex_lock(phil->writem);
// 	// gettimeofday(&phil->current_time,NULL);
// 	printf("%ld %d has taken a fork\n",timeval_comp(phil->table->start) ,phil->id);
// 	pthread_mutex_unlock(phil->writem);
// 	pthread_mutex_lock(phil->right_vilka);	
// 	pthread_mutex_lock(phil->writem);
// 	// gettimeofday(&phil->current_time,NULL);
// 	printf("%ld %d has taken a fork\n%ld %d is eating\n",timeval_comp(phil->table->start) , \
// 	     phil->id,timeval_comp(phil->table->start) , phil->id );
// 	pthread_mutex_lock(phil->check);
// 	// gettimeofday(&phil->last,NULL);
// 	pthread_mutex_unlock(phil->check);
// 	pthread_mutex_unlock(phil->writem);
// 	ft_sleep(phil,phil->table->t_eat);
// 	pthread_mutex_lock(phil->writem);
// 	pthread_mutex_unlock(phil->left_vilka);
// 	pthread_mutex_unlock(phil->right_vilka);
// }

// void procrastination(t_phil *phil)
// {
// 	// gettimeofday(&phil->current_time,NULL);
// 	// pthread_mutex_lock(phil->writem);
// 	printf("%ld %d is sleeping\n",timeval_comp(phil->table->start) ,phil->id);
// 	pthread_mutex_unlock(phil->writem);
// 	ft_sleep(phil,phil->table->t_sleep);
// 	// gettimeofday(&phil->current_time,NULL);
// 	pthread_mutex_lock(phil->writem);
// 	printf("%ld %d is thinking\n",timeval_comp(phil->table->start),phil->id);
// 	pthread_mutex_unlock(phil->writem);
// }

// void	*routine(void *philo)
// {
// 	t_phil *phil;

// 	phil=(t_phil *)philo;
// 	while(phil->times_need_to_eat != 0)
// 	{
// 		eating_process(phil);
// 		procrastination(phil);
// 		phil->times_need_to_eat--;
// 	}
// 	phil->table->done++;
// 	// if(phil->times_need_to_eat == 0)
// 	// 	printf("%d philosophers have eaten the required number of times!\n",timeval_comp(phil->table->start,phil->current_time) / 1000);
// 	return (NULL);
// }




//-----------------------------3
long int	gettime(struct timeval start) // tekuwee vremya kotoroe vivoditsya // dlya eating sleeping etc.
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000 ;
	res-=1000 * (size_t)start.tv_sec + (size_t)start.tv_usec / 1000;
	return (res);
}
long	timeval_comp(struct timeval fst, struct timeval snd)
{
	// return ((snd.tv_sec - fst.tv_sec) * 1000000 + snd.tv_usec - fst.tv_usec);
	return (snd.tv_usec - fst.tv_usec + (snd.tv_sec - fst.tv_sec) * 1000000);
}
void ft_sleep(t_phil *phil, int milisec)
{	
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	gettimeofday(&phil->current_time, NULL);
	while (timeval_comp(phil->current_time, temp)  < milisec * 1000 )
	{
		usleep(20);
		gettimeofday(&temp, NULL);
	}
}
///
long	ft_time(void)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}
void	ft_usleep(int milisec)
{
	long	time;

	time = ft_time();
	usleep(milisec * 920);
	while (ft_time() < time + milisec)
		usleep(milisec);
}
////
void eating(t_phil *phil)
{
	pthread_mutex_lock(phil->left_vilka);
	pthread_mutex_lock(phil->writem);
	// gettimeofday(&phil->current_time,NULL);
	printf("%ld %d has taken a fork\n",gettime(phil->table->start) ,phil->id);
	pthread_mutex_unlock(phil->writem);
	pthread_mutex_lock(phil->right_vilka);	
	pthread_mutex_lock(phil->writem);
	// gettimeofday(&phil->current_time,NULL);
	// printf("%ld---\n",gettime(phil->table->start));
	printf("%ld %d has taken a fork\n%ld %d is eating\n", gettime(phil->table->start)  , \
	     phil->id,gettime(phil->table->start), phil->id );
	pthread_mutex_lock(phil->check);
	gettimeofday(&phil->last,NULL);
	pthread_mutex_unlock(phil->check);
	pthread_mutex_unlock(phil->writem);
	ft_usleep(phil->table->t_eat);     //zdes
	// printf("pohaval\n");
	pthread_mutex_lock(phil->writem);
	pthread_mutex_unlock(phil->left_vilka);
	pthread_mutex_unlock(phil->right_vilka);
}
void procrastination(t_phil *phil)
{
	// gettimeofday(&phil->current_time,NULL);
	// pthread_mutex_lock(phil->writem);
	printf("%ld %d is sleeping\n",gettime(phil->table->start) ,phil->id);
	pthread_mutex_unlock(phil->writem);
	ft_usleep(phil->table->t_sleep);           //zdes
	gettimeofday(&phil->current_time,NULL);
	pthread_mutex_lock(phil->writem);
	printf("%ld %d is thinking\n",gettime(phil->table->start),phil->id);
	pthread_mutex_unlock(phil->writem);
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
		// printf("%ld\n",gettime(table->start));
		// printf("%ld\n",gettime(table->philos[i].last));
		// printf("--%d\n",timeval_comp(table->philos[i].last,tmp) / 1000);
		// if (gettime(table->start) - table->start > table->t_die && table->philos[i].times_need_to_eat)
		if (timeval_comp(table->philos[i].last, tmp) / 1000 > table->t_die && table->philos[i].times_need_to_eat)
		{
			pthread_mutex_lock(&(table->writem));
			printf("%ld %d died\n", timeval_comp(table->start, tmp) \
			/ 1000, i + 1);
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
	t_phil *phil;

	phil=(t_phil *)philo;
	while(phil->times_need_to_eat != 0)
	{
		eating(phil);
		procrastination(phil);
		phil->times_need_to_eat--;
	}
	phil->table->done++;
	return (NULL);
}