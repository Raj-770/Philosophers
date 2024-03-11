/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:11:20 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/11 09:25:20 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int		check_meals(t_table *table, int *j);
void	check_death(t_philo *philo);

int	start(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&table->philos[i].routine, NULL, &routine, \
		(void *)&table->philos[i]) != 0)
			return (0);
		table->threads_ready++;
		i++;
	}
	ft_usleep(table->t_die + 1);
	while (table->all_good)
		monitor_death(table);
	return (1);
}

void	monitor_death(void *t)
{
	t_table	*table;
	int		i;
	int		j;

	table = (t_table *)t;
	i = 0;
	j = 0;
	while (table->all_good)
	{
		check_death(&table->philos[i]);
		if (check_meals(table, &j) == 1)
			table->all_good = 0;
		if (i == table->n_philo -1)
			i = -1;
	}
}

void	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->eat);
	if (get_current_time() - philo->t_last_ate > philo->table->t_die)
	{
		print_action("died", philo, get_current_time());
		philo->table->all_good = 0;
	}
	pthread_mutex_unlock(&philo->table->eat);
}

int	check_meals(t_table *table, int *j)
{
	if (table->max_meals > 0)
	{
		while (*j < table->n_philo)
		{
			if (table->philos[*j].n_times_ate < table->max_meals)
				break ;
			(*j)++;
		}
	}
	if (*j == table->n_philo)
		return (1);
	return (0);
}
