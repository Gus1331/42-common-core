/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:30:02 by gustaoli          #+#    #+#             */
/*   Updated: 2025/11/22 15:36:19 by gustaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_philo(const t_philo *p)
{
    printf("====== PHILO ======\n");
    printf("ID: %d\n", p->id + 1);
    printf("Thread: %lu\n", (unsigned long)p->thread);
    printf("Forks: [%d, %d]\n", p->forks[0], p->forks[1]);
    printf("Times eaten: %d\n", p->times_eaten);
    printf("===================\n");
}

void	start_threads(t_philo *philos)
{
	int	i;
	
	i = 0;
	while (i < philos->rules->n_philo)
	{
		pthread_create(&philos[i].thread, NULL, routine, &(philos[i]));
		i++;
	}
}

void	wait_threads(t_philo *philos)
{
	int	i;

	while (!check_all_philos_eaten(philos) && !check_philo_starved(philos))
		usleep(500);
	i = 0;
	while (i < philos->rules->n_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_rules	*rules;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (1);
	rules = init_data(argc, ++argv);
	if (!rules)
		return (1);
	philos = init_philos(rules);
	if (!philos)
		return (1);
	start_threads(philos);
	wait_threads(philos);
	free_data(rules);
	free(philos);
	return (0);
}
