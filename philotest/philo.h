#ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include <string.h>
// #include "libft/libft.h"

typedef struct s_phil
{
	pthread_mutex_t	*left_vilka;
	pthread_mutex_t	*right_vilka;
	int		id;
	// int				last_eat;
	// int				limit;
	// int				count_eat;
	int times_need_to_eat;
	pthread_mutex_t	*writem;
	pthread_mutex_t	*check;
	pthread_t		self;
	struct timeval	current_time;
	struct timeval	last;
	// struct timeval	tek; tek vremya
	// struct timeval	last; kogda last raz haval
	// int				n; nomer filosofa
	// int				rep; skolko  raz pohavat
	struct s_table	*table;
	time_t			start_time;
}				t_phil;
 
typedef struct s_table
{
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				num;
	int				times_need_to_eat;
	int				done;
	pthread_mutex_t	*vilki;
	pthread_mutex_t	writem;
	pthread_mutex_t	*checks;
	// pthread_mutex_t	printm;mutex na printf
	t_phil			*philos;
	struct timeval	start;
	// pthread_mutex_t	smb_dead;
}				t_table;


size_t	ft_strlen(const char *str);
int	ft_atoi(const char *str);
void	*routine(void *philo);
void eating_process(t_phil *phil);
void procrastination(t_phil *phil);
void ft_sleep(t_phil *phil, int milisec);
void is_smb_dead(t_table *table);
long	ft_time(void);


#endif