/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/02 16:56:45 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (!philo->id % 2)
		usleep(1500);
	while (philo->table->all_good)
	{
		if (philo->table->max_meals > 0 && philo->n_times_ate == philo->table->max_meals)
		{
			philo->table->all_good = 0;
			break ;
		}
		philo_eats(philo);
		philo_sleeps(philo);
		philo_thinks(philo);
	}
	pthread_exit(NULL);
}