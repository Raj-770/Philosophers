/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:20:50 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/02 16:46:09 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init(t_table *table)
{
	int	i;
	int	n;

	i = 0;
	n = table->n_philo;
	table->all_good = 1;
	table->start_time = 0;
	table->start_signal = 0;
	table->forks = (pthread_mutex_t *)malloc(n * sizeof(pthread_mutex_t));
	table->philos = (t_philo *)malloc(n * sizeof(t_philo));
	pthread_mutex_init(&table->print, NULL);
	if (table->philos == NULL || table->forks == NULL)
		return (0);
	while (i < n)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (0);
		table->philos[i].id = i + 1;
		table->philos[i].fork_left = i;
		table->philos[i].fork_right = (i + 1) % n;
		table->philos[i].table = table;
		i++;
	}
	return (1);
}
