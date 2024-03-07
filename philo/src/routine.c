/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/06 15:59:27 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Issue: Delay after the last meal of even numbered philos

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1) {
        pthread_mutex_lock(&philo->table->start_mutex);
        if (philo->table->start_signal) {
            pthread_mutex_unlock(&philo->table->start_mutex);
			philo->table->start_time = get_current_time();
            break;
        }
        pthread_mutex_unlock(&philo->table->start_mutex);
    }
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->t_eat / 10);
	while (philo->table->all_good)
	{
		philo_eats(philo);
		philo_sleeps(philo);
		philo_thinks(philo);
		if (philo->table->max_meals > 0 && philo->n_times_ate == \
		philo->table->max_meals)
			break ;
	}
	return (NULL);
}
