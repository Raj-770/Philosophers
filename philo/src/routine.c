/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/11 13:14:09 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *p)
{
	t_philo	*philo;
	bool	all_thread_ready;

	philo = (t_philo *)p;
	all_thread_ready = false;
	while (1)
	{
		pthread_mutex_lock(&philo->table->start_mutex);
		all_thread_ready = philo->table->threads_ready == philo->table->n_philo;
		pthread_mutex_unlock(&philo->table->start_mutex);
		if (all_thread_ready)
		{
			pthread_mutex_lock(&philo->table->print);
			philo->table->start_time = get_current_time();
			pthread_mutex_unlock(&philo->table->print);
			usleep(10);
			break ;
		}
		usleep(1);
	}
	philo_do(philo);
	return (NULL);
}

void	philo_do(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1500);
	while (philo->table->all_good)
	{
		if (philo->table->n_philo == 1)
		{
			philo_eats(philo);
			return ;
		}
		philo_eats(philo);
		if (philo->table->max_meals > 0 && philo->n_times_ate == \
		philo->table->max_meals)
			return ;
		philo_sleeps(philo);
		philo_thinks(philo);
	}
}
