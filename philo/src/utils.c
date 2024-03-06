/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:03:36 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/06 15:07:13 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	put_nbr(long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		put_nbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	print_action(char *action, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	put_nbr(get_current_time() - philo->table->start_time);
	put_str(" Philo ");
	put_nbr(philo->id);
	write(1, " ", 1);
	put_str(action);
	write(1, "\n", 1);
	pthread_mutex_unlock(&philo->table->print);
}

// void	print_action(char *action, t_philo *philo)
// {
// 	long	time;

// 	pthread_mutex_lock(&philo->table->print);
// 	time = -1;
// 	time = get_current_time() - philo->table->start_time;
// 	if (time >= 0 && time <= 2147483647)
// 	{
// 		printf("%ld ", time);
// 		printf("Philo %d %s\n", philo->id, action);
// 	}
// 	pthread_mutex_unlock(&philo->table->print);
// }