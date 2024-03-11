/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:32:19 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/11 13:54:03 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	which_to_pick_first(int *first_fork, int *second_fork, t_philo *p);

void	philo_eats(t_philo *philo)
{
	int	forks[2];

	which_to_pick_first(&forks[0], &forks[1], philo);
	if (philo->threads_all_good)
	{
		pthread_mutex_lock(&philo->table->forks[forks[0]]);
		if (philo->table->n_philo == 1)
		{
			print_action("has taken a fork", philo);
			ft_usleep(philo->table->t_die + 1);
			pthread_mutex_unlock(&philo->table->forks[forks[0]]);
			return ;
		}
		pthread_mutex_lock(&philo->table->forks[forks[1]]);
		print_action("has taken a fork", philo);
		print_action("has taken a fork", philo);
		print_action("is eating", philo);
		pthread_mutex_lock(&philo->table->eat);
		philo->t_last_ate = get_current_time();
		philo->n_times_ate++;
		pthread_mutex_unlock(&philo->table->eat);
		ft_usleep(philo->table->t_eat);
		pthread_mutex_unlock(&philo->table->forks[forks[1]]);
		pthread_mutex_unlock(&philo->table->forks[forks[0]]);
	}
}

void	philo_sleeps(t_philo *philo)
{
	if (philo->threads_all_good)
	{
		print_action("is sleeping", philo);
		ft_usleep(philo->table->t_sleep);
	}
}

void	philo_thinks(t_philo *philo)
{
	if (philo->threads_all_good)
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
