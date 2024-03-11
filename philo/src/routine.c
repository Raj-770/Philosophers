/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/11 10:42:59 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *p)
{
	t_philo	*philo;
	bool	all_threads_ready;

	philo = (t_philo *)p;
	all_threads_ready = false;
	while (1)
	{
		pthread_mutex_lock(&philo->table->start_mutex);
		all_threads_ready = philo->table->threads_ready == philo->table->n_philo;
		pthread_mutex_unlock(&philo->table->start_mutex);
		if (all_threads_ready)
			break ;
		usleep(1);
	}
	if (!philo->table->start_signal)
	{
		philo->table->start_time = get_current_time();
		philo->table->start_signal = 1;
	}
	if (philo->id % 2 == 0)
		usleep(1500);
	while (philo->table->all_good)
	{
		if (philo->table->n_philo == 1)
		{
			philo_eats(philo);
			return (NULL);
		}
		philo_eats(philo);
		if (philo->table->max_meals > 0 && philo->n_times_ate == \
		philo->table->max_meals)
			return (NULL);
		philo_sleeps(philo);
		philo_thinks(philo);
	}
	return (NULL);
}
