/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:48:09 by dshirely          #+#    #+#             */
/*   Updated: 2022/05/02 18:50:35 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	gettime(struct timeval start)
{
	struct timeval	tv;
	long			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000 ;
	res -= 1000 * (size_t)start.tv_sec + (size_t)start.tv_usec / 1000;
	return (res);
}

long	timeval_comp(struct timeval fst, struct timeval snd)
{
	return (snd.tv_usec - fst.tv_usec + (snd.tv_sec - fst.tv_sec) * 1000000);
}

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
		usleep(milisec * 3);
}
