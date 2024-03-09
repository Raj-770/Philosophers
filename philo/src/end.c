/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:33:07 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/09 14:15:31 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end(t_table *table)
{
	int	i;

	i = 0;
	// ft_usleep(1);
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
	free(table->philos);
	free(table->forks);
}
