/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/10 17:47:45 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (philo->table->start_signal == 0)
		usleep(1);
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
			return (NULL) ;
		philo_sleeps(philo);
		philo_thinks(philo);
	}
	return (NULL);
}
