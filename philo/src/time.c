/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:59:23 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/17 17:39:52 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief Get the current time in miliseconds by getting the time from
 * gettimeofday function and converting the time recieved in seconds and
 * microseconds into mili seconds.
 *
 * @return long the current time of day in milisecods
 */
long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * @brief usleep the process precisely for the given duration,
 * by calling the usleep function for a fraction of the given duration
 * again and again till the duration is passesd.
 *
 * @param duration
 */
void	ft_usleep(long int duration, t_philo *philo)
{
	long int	i;

	i = get_current_time();
	while ((get_current_time() - i) < duration)
	{
		pthread_mutex_lock(&philo->table->copy_mutex);
		philo->threads_all_good = philo->table->all_good;
		if (!philo->threads_all_good)
		{
			pthread_mutex_unlock(&philo->table->copy_mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->table->copy_mutex);
		usleep(duration / 10);
	}
}
