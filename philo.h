/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:16:24 by dshirely          #+#    #+#             */
/*   Updated: 2022/05/02 18:50:18 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_phil
{
	pthread_mutex_t	*left_vilka;
	pthread_mutex_t	*right_vilka;
	int				id;
	int				times_need_to_eat;
	pthread_mutex_t	*writem;
	pthread_mutex_t	*check;
	pthread_t		self;
	struct timeval	current_time;
	struct timeval	last;
	struct s_table	*table;
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
	t_phil			*philos;
	struct timeval	start;
}				t_table;

size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
void		*routine(void *philo);
void		eating_process(t_phil *phil);
void		procrastination(t_phil *phil);
void		ft_sleep(t_phil *phil, int milisec);
void		is_smb_dead(t_table *table);
void		parser(int argc, char **argv, t_table *table);
int			exit_error(char const *str);
int			philo_init(t_table *table, int i);
int			philos_creator(t_table *table);
int			mutex_creator(t_table *table);
int			ft_check_input(t_table *table, int argc);
void		ft_free(t_table *table);
long int	gettime(struct timeval start);
void		ft_usleep(int milisec);
long		timeval_comp(struct timeval fst, struct timeval snd);

#endif