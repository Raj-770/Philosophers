/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:01:46 by rpambhar          #+#    #+#             */
/*   Updated: 2024/03/06 11:13:53 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!parse_args(argc, argv, &table))
		return (put_str("ERROR: Invalid Input\n"), EXIT_FAILURE);
	if (!init(&table))
		return (put_str("ERROR: Initialization Failed\n"), EXIT_FAILURE);
	if (!start(&table))
		return (put_str("ERROR: Thread Creation Failed\n", EXIT_FAILURE));
	end(&table);
}
