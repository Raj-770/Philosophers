/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:32:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/06 15:57:24 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eats(t_philo *philo)
{
	int lower_fork;
	int higher_fork;

	if (philo->fork_left < philo->fork_right) {
        lower_fork = philo->fork_left;
        higher_fork = philo->fork_right;
    } else {
        lower_fork = philo->fork_right;
        higher_fork = philo->fork_left;
    }
	 if (philo->table->all_good)
    {
        // Lock the lower ID fork first
        pthread_mutex_lock(&philo->table->forks[lower_fork]);
        print_action("has taken a fork", philo, get_current_time());

        // Then lock the higher ID fork
        pthread_mutex_lock(&philo->table->forks[higher_fork]);
        print_action("has taken a fork", philo, get_current_time());

        // The philosopher can now eat
        print_action("is eating", philo, get_current_time());
        pthread_mutex_lock(&philo->table->eat); // Protect shared state access
        philo->t_last_ate = get_current_time();
        philo->n_times_ate++;
        pthread_mutex_unlock(&philo->table->eat);

        ft_usleep(philo->table->t_eat);

        // Unlock the forks in the reverse order of locking
        pthread_mutex_unlock(&philo->table->forks[higher_fork]);
        pthread_mutex_unlock(&philo->table->forks[lower_fork]);
    }
}

void	philo_sleeps(t_philo *philo)
{
	if (philo->table->all_good)
	{
		print_action("is sleeping", philo, get_current_time());
		ft_usleep(philo->table->t_sleep);
	}
}

void	philo_thinks(t_philo *philo)
{
	if (philo->table->all_good)
		print_action("is thinking", philo, get_current_time());
}
