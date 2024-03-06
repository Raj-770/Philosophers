/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:16:12 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/06 13:49:55 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		ft_usleep(philo->table->t_eat / 10);
	while (1)
	{
		philo_eats(philo);
		philo_sleeps(philo);
		philo_thinks(philo);
		if (philo->table->max_meals > 0 && philo->n_times_ate == philo->table->max_meals)
		{
			philo->table->all_good = 0;
			break ;
		}
	}
	return NULL;
}
