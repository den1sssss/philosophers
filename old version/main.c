#include "philo.h"
int ft_check_input(t_table *table)
{
	if(table->num < 1 || table->t_die <  60 || table->t_eat < 60 || \
		table->t_sleep < 60)
	{
		printf("error\nCheck your input!\n");
		return (1);
	}
	return (0);
}
void parser(int argc, char **argv, t_table *table)
{
	table->num=ft_atoi(argv[1]);
	table->t_die=ft_atoi(argv[2]);
	table->t_eat=ft_atoi(argv[3]);
	table->t_sleep=ft_atoi(argv[4]);
	if(argc == 6)
		table->rep =ft_atoi(argv[5]);

}

// void ft_sleep(long ms)
// {
// 	struct timeval a;
// 	long	start;

// 	gettimeofday(&a, NULL);
// 	start = a.tv_sec * 1000000 + a.tv_usec;
// 	while (1)
// 	{
// 		gettimeofday(&a, NULL);
// 		if (a.tv_sec * 1000000 + a.tv_usec - start > 1000 * ms)
// 			break;
// 	}
// }

void mutex_creator(t_table *table)
{
	int i;

	i = 0;
	table->vilki=(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->num);
	if(!table->vilki)
	{
		printf("Mutex error\n");
		return ;
	}
	while(i < table->num)
	{
		if(pthread_mutex_init(&table->vilki[i++],NULL) != 0)
		{
			printf("mutex_init error\n");
			return ;
		}
	}
}


void philo_creator(t_table *table)//here we're making threads
{
	int i;

	i = 0;
	table->philos=(t_phil *)malloc(sizeof(t_phil) * table->num);
	if(!table->philos)
	{
		printf("Philo creator error\n");
		return ;
	}
	while(i < table->num)
	{
		if(pthread_create(&table->philos[i],NULL,'   ',NULL))  
		{
			printf("Thread creating error\n");
			return ;
		}
		i++;
	}



}
// void gettime(t_table *table)
// {


// }§

int main(int argc,char**argv)
{
	t_table table;

	if (argc == 5 || argc == 6)
	{
		parser(argc,argv,&table);
		if(ft_check_input(&table))
			return (1);
		mutex_creator(&table);
		// gettime(&table);
		philo_creator(&table);
		//
		// vilki_init();
		// philo_init();
		// sleep(1000);
	}
	else
	{
		printf("Incorrect input\n");
		return (0);
	}
}