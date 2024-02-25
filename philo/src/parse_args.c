/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:46:08 by rpambhar          #+#    #+#             */
/*   Updated: 2024/02/25 15:14:24 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	validate_inputs(int argc, char **argv, t_table *table);
static int	ft_atoi(const char *str);

/**
 * @brief validates and stores the data passed by the user
 *
 * @param argc number of arguments
 * @param argv value of arguments
 * @param data structure used for storing data passed by the user
 * @return int return 0 if error found else return 1
 */
int	parse_args(int argc, char **argv, t_table *table)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!validate_inputs(argc, argv, table))
		return (0);
	return (1);
}

/**
 * @brief Helper function for parse_args function
 *
 * @param argc
 * @param argv
 * @param data
 * @return int return 0 if error found else return 1
 */
static int	validate_inputs(int argc, char **argv, t_table *table)
{
	int	a;
	int	e;

	a = ft_atoi(argv[1]);
	e = -1;
	if (argc == 6)
		e = ft_atoi(argv[5]);
	if (a > 0 && a <= 200 && ft_atoi(argv[2]) > 0 && ft_atoi(argv[3]) > 0 \
	&& ft_atoi(argv[4]) > 0)
	{
		table->n_philo = a;
		table->t_die = ft_atoi(argv[2]);
		table->t_eat = ft_atoi(argv[3]);
		table->t_sleep = ft_atoi(argv[4]);
		if (argc == 6 && e > 0)
			table->max_meals = e;
		if (argc == 6 && e <= 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

/**
 * @brief Helper function which converts string into integer
 *
 * @param str takes a string of digits as an input
 * @return int return the converted integer
 */
static int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
