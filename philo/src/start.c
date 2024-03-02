/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:11:20 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/02 12:14:03 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		pthread_create(&table->philos[i].thread, NULL, routine, (void *)&table->philos[i]);
		i++;
	}
}