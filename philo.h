#ifndef PHLIHO_H
# define PHILO_H
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <libft/libft.h>

typedef struct s_phil
{
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rg;
	pthread_t		self;
	struct timeval	tek;
	struct timeval	last;
	int				n;
	int				rep;
	struct s_gen	*data;
}				t_phil;
 
typedef struct s_gen
{
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				num;
	int				rep;
	int				doa;
	pthread_mutex_t	*vilki;
	pthread_mutex_t	printm;
	t_phil			*phils;
	struct timeval	start;
}				t_gen;

#endif