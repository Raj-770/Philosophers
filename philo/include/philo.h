/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:52:13 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/11 10:34:51 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int			id;
	int			n_times_ate;
	int			fork_left;
	int			fork_right;
	long		t_last_ate;
	t_table		*table;
	pthread_t	routine;
}	t_philo;

typedef struct s_table
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_meals;
	int				all_good;
	long			start_time;
	int				start_signal;
	int				threads_ready;
	int				finished_meals;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	death_monitor;
}	t_table;

// Utility functions for printing information
void	put_str(char *str);
void	put_nbr(long n);
// void	print_action(char *action, t_philo *philo);
void	print_action(char *action, t_philo *philo, long int current_time);

// Parsing user input
int		parse_args(int argc, char **argv, t_table *table);

// Initializes philos and forks
int		init(t_table *table);
int		initialize_table(t_table *table);
int		initialize_philos(t_table *table);

// Time Functions
long	get_current_time(void);
void	ft_usleep(long int duration);

// Routine
void	*routine(void *p);
void	monitor_death(void *t);

// Philo Actions
void	philo_eats(t_philo *philo);
void	philo_sleeps(t_philo *philo);
void	philo_thinks(t_philo *philo);

// Start and End
int		start(t_table *table);
void	end(t_table *table);

#endif