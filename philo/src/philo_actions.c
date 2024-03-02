/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:32:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/02 13:04:39 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eats(t_philo *philo)
{
	if (philo->table->all_good)
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork_left]);
		print_action("has taken a fork", philo);
		pthread_mutex_lock(&philo->table->forks[philo->fork_right]);
		print_action("has taken a fork", philo);
		print_action("is eating", philo);
		philo->t_last_ate = get_current_time();
		philo->n_times_ate++;
		ft_usleep(philo->table->t_eat);
		pthread_mutex_unlock(&philo->table->forks[philo->fork_left]);
		pthread_mutex_unlock(&philo->table->forks[philo->fork_right]);
	}
}

void	philo_sleeps(t_philo *philo)
{
	if (philo->table->all_good)
	{
		print_action("has taken a fork", philo);
		ft_usleep(philo->table->t_sleep);
	}
}

void	philo_thinks(t_philo *philo)
{
	if (philo->table->all_good)
		print_action("is thinking", philo);
}