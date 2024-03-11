/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:33:07 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/11 13:13:11 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_join(table->philos[i].routine, NULL);
		i++;
	}
	i = 0;
	while (i < table->n_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->eat);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->start_mutex);
	free(table->philos);
	free(table->forks);
}
