/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:11:20 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/06 11:08:00 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = get_current_time();
	while (i < table->n_philo)
	{

		pthread_create(&table->philos[i].routine, NULL, &routine, (void *)&table->philos[i]);
		i++;
	}
}
