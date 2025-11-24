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

int	main(int argc, char **argv)
{
	t_rules	*rules;
	// t_philo	*philos;

	long start = get_time();
	if (argc < 5 || argc > 6)
		return (1);
	rules = init_data(argc, ++argv);
	if (!rules)
		return (1);
	// philos = init_philos(*rules);
	// for (int i = 0; i < rules->n_philo; i++){
	// 	print_philo(&(philos[i]));
	// }
	free_data(rules);
	usleep(1000000 * 50);
	printf("Tempo de execução: %ld\n", (get_time() - start) / 1000);
	return (0);
}
