/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:11:20 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/06 15:59:37 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	start(t_table *table)
{
	pthread_t monitorThread;
	int	i;

	i = 0;
	if (pthread_create(&monitorThread, NULL, &monitor_death, (void *)table) != 0)
		return (0);
	 while (i < table->n_philo) {
        if (pthread_create(&table->philos[i].routine, NULL, &routine, (void *)&table->philos[i]) != 0)
            return (0); // Handle thread creation failure

        pthread_mutex_lock(&table->start_mutex);
        table->threads_ready++;
        if (table->threads_ready == table->n_philo) {
            table->start_signal = 1; // Signal all threads to start
        }
        pthread_mutex_unlock(&table->start_mutex);

        i++;
    }
	pthread_join(monitorThread, NULL);
	return (1);
}

void	*monitor_death(void *p)
{
	t_table	*table;
	int		i;
	long	current_time;
	
	table = (t_table *)p;
	ft_usleep(table->t_die + 1);
	while (table->all_good)
	{
		i = 0;
		while (i < table->n_philo)
		{
			pthread_mutex_lock(&table->eat);
			current_time = get_current_time();
			if ((current_time - table->philos[i].t_last_ate >= table->t_die) && table->all_good)
			{
				table->all_good = 0;
				print_action("died", &table->philos[i], get_current_time());
				pthread_mutex_unlock(&table->eat);
				return (NULL);
			}
			pthread_mutex_unlock(&table->eat);
			ft_usleep(1);
		}
	}
	return (NULL);
}