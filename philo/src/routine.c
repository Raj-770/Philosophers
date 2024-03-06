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
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->t_eat / 10);
	while (philo->table->all_good)
	{
		pthread_create(&philo->death, NULL, monitor_death, philo);
		philo_eats(philo);
		philo_sleeps(philo);
		philo_thinks(philo);
		pthread_detach(philo->death);
		if (philo->table->max_meals > 0 && philo->n_times_ate == \
		philo->table->max_meals)
			break ;
	}
	return (NULL);
}

void	*monitor_death(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	ft_usleep(philo->table->t_die + 1);
	pthread_mutex_lock(&philo->table->eat);
	if (philo->table->all_good && ((get_current_time() - philo->t_last_ate) >= \
	(long) philo->table->t_die))
	{
		philo->table->all_good = 0;
		print_action("died", philo);
		pthread_mutex_unlock(&philo->table->eat);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->table->eat);
	return (NULL);
}
