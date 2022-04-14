#ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_phil
{
	pthread_mutex_t	*min_vilka;
	pthread_mutex_t	*max_vilka;
	pthread_t		id;
	// struct timeval	tek; tek vremya
	// struct timeval	last; kogda last raz haval
	// int				n; nomer filosofa
	// int				rep; skolko  raz pohavat
	struct s_table	*table;
}				t_phil;
 
typedef struct s_table
{
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				num;
	int				rep; //skoko raz havat nado
	pthread_mutex_t	*vilki;
	// pthread_mutex_t	printm;mutex na printf
	t_phil			*philos;
	struct timeval	start;
}				t_table;

#endif