/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:32:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/17 17:09:45 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	which_to_pick_first(int *first_fork, int *second_fork, t_philo *p);

void	philo_eats(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	which_to_pick_first(&first_fork, &second_fork, philo);
	pthread_mutex_lock(&philo->table->forks[first_fork]);
	print_action("has taken a fork", philo);
	if (philo->table->n_philo == 1)
	{
		ft_usleep(philo->table->t_die + 1);
		pthread_mutex_unlock(&philo->table->forks[first_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->table->forks[second_fork]);
	print_action("has taken a fork", philo);
	print_action("is eating", philo);
	pthread_mutex_lock(&philo->table->eat);
	philo->t_last_ate = get_current_time();
	pthread_mutex_unlock(&philo->table->eat);
	philo->n_times_ate++;
	ft_usleep(philo->table->t_eat);
	pthread_mutex_unlock(&philo->table->forks[second_fork]);
	pthread_mutex_unlock(&philo->table->forks[first_fork]);
}

void	philo_sleeps(t_philo *philo)
{
	print_action("is sleeping", philo);
	ft_usleep(philo->table->t_sleep);
}

void	philo_thinks(t_philo *philo)
{
	print_action("is thinking", philo);
}

static void	which_to_pick_first(int *first_fork, int *second_fork, t_philo *p)
{
	if (p->fork_left < p->fork_right)
	{
		*first_fork = p->fork_left;
		*second_fork = p->fork_right;
	}
	else
	{
		*first_fork = p->fork_right;
		*second_fork = p->fork_left;
	}
}